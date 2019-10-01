#include <stdio.h>
#include <stdlib.h>

#include <dyllib.h>

void testLinkedList(void);
void testString(void);
void testDictionary(void);
void testMiscellaneous(void);

#ifdef DLIBGRAPHICS
void testGraphics(void);
#endif

int main(int argc, char** args) {
    //printf("Hello, world!\n");
    //testLinkedList();
    //testString();
    //testDictionary();
    //testMiscellaneous();
    #ifdef DLIBGRAPHICS
    testGraphics();
    #endif

    return 0;
}

#ifdef DLIBGRAPHICS
// OpenGL on linux
#ifdef __linux__
    #include <X11/X.h>
    #include <X11/Xlib.h>
    #include <GL/gl.h>
    #include <GL/glx.h>
    #include <GL/glu.h>

    Display                 *disp;
    Window                  root;
    GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    XVisualInfo             *vi;
    Colormap                cmap;
    XSetWindowAttributes    swa;
    Window                  win;
    GLXContext              glc;
    XWindowAttributes       gwa;
    XEvent                  xev;

    void drawTestQuad(void) {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1., 1., -1., 1., 1., 20.);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);

        glBegin(GL_QUADS);
            glColor3f(1., 0., 0.); glVertex3f(-.75, -.75, 0.);
            glColor3f(0., 1., 0.); glVertex3f( .75, -.75, 0.);
            glColor3f(0., 0., 1.); glVertex3f( .75,  .75, 0.);
            glColor3f(1., 1., 0.); glVertex3f(-.75,  .75, 0.);
        glEnd();
    }

    void testGraphics(void) {
        disp = XOpenDisplay(NULL);

        if(disp == NULL) {
            printf("Cannot connect to X Display Server\n");
            exit(0);
        }

        root = DefaultRootWindow(disp);

        vi = glXChooseVisual(disp, 0, att);

        if(vi == NULL) {
            printf("No appropriate visual found\n");
            exit(0);
        } else
            printf("Visual %p selected\n", (void *)vi->visualid);

        cmap = XCreateColormap(disp, root, vi->visual, AllocNone);
        swa.colormap = cmap;
        swa.event_mask = ExposureMask | KeyPressMask;

        win = XCreateWindow(disp, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
        XMapWindow(disp, win);
        XStoreName(disp, win, "Graphics test");

        glc = glXCreateContext(disp, vi, NULL, GL_TRUE);
        glXMakeCurrent(disp, win, glc);

        glEnable(GL_DEPTH_TEST);
        while(1) {
            XNextEvent(disp, &xev);

            if(xev.type == Expose) {
                XGetWindowAttributes(disp, win, &gwa);
                glViewport(0, 0, gwa.width, gwa.height);
                drawTestQuad();
                glXSwapBuffers(disp, win);
            } else if(xev.type == KeyPress) {
                glXMakeCurrent(disp, None, NULL);
                glXDestroyContext(disp, glc);
                XDestroyWindow(disp, win);
                XCloseDisplay(disp);
                exit(0);
            }
        }
    }
#elif __WIN32 || __WIN64
    // Not implemented yet. Sorry windows users :/ When I get a chance I'll add it.
#elif __APPLE__
    // Probably not gonna be implemented ever. Don't ever plan on using that stuff.
    // Maybe try to build with X? I think that's something that's doable if I'm not mistaken
#endif
#endif

void testMiscellaneous(void) {
    // File IO
    string *main_c_src = dlib.fscantext("src/main.c");                  // This works
    //printf("\n%s\n", main_c_src->val);
    dlib.fprinttext("test1.o", main_c_src);
    dlib.deleteString(main_c_src);

    list *main_c_src_lines = dlib.fscanlines("src/main.c");
    //for(int i = 0; i < main_c_src_lines->length; i++)
    //    printf("%s\n", (char *) dlib.accessList(main_c_src_lines, i));
    dlib.fprintlines("test2.o", main_c_src_lines);
    dlib.deleteList(main_c_src_lines);
}

void testDictionary(void) {
    dict *test = dlib.newDict();

    printf("Testing basic add/get:\n");
    dlib.addToDict(test, "taco", dlib.heapInt(1));
    dlib.addToDict(test, "burrito", dlib.heapInt(2));
    dlib.addToDict(test, "pasta", dlib.heapInt(3));

    printf("dict[\"taco\"] = %d\n", *(int *)dlib.getFromDict(test, "taco"));
    printf("dict[\"burrito\"] = %d\n", *(int *)dlib.getFromDict(test, "burrito"));
    printf("dict[\"pasta\"] = %d\n", *(int *)dlib.getFromDict(test, "pasta"));

    dlib.removeFromDict(test, "taco");
    printf("dict[\"burrito\"] = %d\n", *(int *)dlib.getFromDict(test, "burrito"));
    printf("dict[\"pasta\"] = %d\n", *(int *)dlib.getFromDict(test, "pasta"));
    if(dlib.getFromDict(test, "taco") == NULL)
        printf("Success!\n");
    else
        printf("Failure!\n");
    printf("%d\n", test->length);
    dlib.setDict(test, "burrito", dlib.heapInt(127));
    printf("dict[\"burrito\"] = %d\n", *(int *)dlib.getFromDict(test, "burrito"));

    printf("Freeing dict\n");
    dlib.deleteDict(test);
}

void testString(void) {
    string *str = dlib.newString();

    printf("Testing append string:\n");
    dlib.appendString(str, "Hello, world!");
    printf("%s\n", str->val);
    dlib.appendString(str, str->val);
    printf("%s\n", str->val);
    dlib.appendString(str, "DEATH");
    printf("%s\n", str->val);
    printf("Freeing string\n");
    dlib.deleteString(str);

    printf("Testing insertion:\n");
    str = dlib.newString();
    dlib.appendString(str, "NEWSTRING");
    printf("%s\n", str->val);
    dlib.insertString(str, 0, "BLAH");
    printf("%s\n", str->val);
    dlib.insertString(str, 5, "BLAH");
    printf("%s\n", str->val);
    dlib.insertString(str, str->len - 1, "BLAH");
    printf("%s\n", str->val);
    printf("Freeing string\n");
    dlib.deleteString(str);

    printf("Testing substring:\n");
    str = dlib.newString();
    dlib.appendString(str, "Hello, world!");
    printf("%s\n", str->val);
    string *str2 = dlib.substring(str, 1, 4);
    printf("%s\n", str2->val);
    printf("%d\n", str2->len);
    printf("Freeing strings\n");
    dlib.deleteString(str);
    dlib.deleteString(str2);

    printf("Testing removal:\n");
    str = dlib.newString();
    dlib.appendString(str, "HELLO WORLD!");
    printf("%s\n", str->val);
    dlib.removeString(str, 0, 5);
    printf("%s\n", str->val);
    dlib.insertString(str, 0, "THE");
    printf("%s\n", str->val);
    printf("%d\n", str->len);
    printf("Freeing string\n");
    dlib.deleteString(str);
}

void testLinkedList(void) {
    list *test = dlib.newList();
    printf("%d\n", test->head->index);

    printf("Testing Basic Append:\n");

    for(int i = 0; i < 10; i++)
        dlib.appendList(test, dlib.heapInt(i));
    
    dlib.debugPrintList(test);

    printf("Testing Insertion:\n");
    for(int i = 5; i < 10; i++)
        dlib.insertInList(test, 5, dlib.heapInt(i));

    dlib.debugPrintList(test);

    printf("Testing Removal:\n");
    for(int i = 0; i < 3; i++)
        dlib.removeFromList(test, 2);

    dlib.debugPrintList(test);

    printf("Freeing list\n");
    dlib.deleteList(test);
}
