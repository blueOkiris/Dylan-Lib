# Name of binary
OBJNAME=   dyllibtest

# Input files that aren't for library (i.e. tests)
SRC=       src/main.c

# Files specifically for building library
LIB_SRC=   src/dyllib.c src/list.c src/str.c src/dict.c
LIB_OBJ=   $(subst src,bin,$(subst .c,.o,$(LIB_SRC)))

# Library locations for headers
# Default is headers folder
INC=       -Iinclude 

# Compile options
# gcc is the default compiler
# -g is for debug
# -Wall shows all warnings
CC=        gcc
CFLAGS=    -g -Wall

# Build everything
test: $(SRC) lib
	$(CC) $(INC) $(SRC) $(CFLAGS) -o $(OBJNAME) -L. -ldyllib -lX11 -lGL -lGLU

# Compile dyllib source and put obj's in bin folder
$(LIB_OBJ): $(LIB_SRC) bin
	$(CC) -c $(subst bin,src,$(subst .o,.c,$@)) $(INC) $(CFLAGS) -o $@

# Create bin folder if it doesn't exist
bin:
	mkdir bin

# Combine all the bin files into a single library and link graphics
# Essentially with the single static library and the single header file, a user has access to all functionality
lib: $(LIB_OBJ)
	ar rcs libdyllib.a $(LIB_OBJ)

# Just remove everything (except graphics lib bc that takes FOREVER to compile)
# Also it's not my code, so I shant worry about recompiling it. I'll assume it's good
.PHONY: clean
clean:
	rm -rf bin/
	rm $(OBJNAME)
	rm libdyllib.a
	rm *.o
	rm vgcore*
