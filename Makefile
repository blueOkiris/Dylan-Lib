# Name of binary
OBJNAME= dyllibtest

# Input files that aren't for library (i.e. tests)
SRC=    src/main.c

# Files specifically for building library
LIB_SRC= src/dyllib.c src/list.c src/str.c src/dict.c
LIB_OBJ= $(subst src,bin,$(subst .c,.o,$(LIB_SRC)))

# Library locations for headers
# Default is headers folder
INC=     -Iheaders

# Compile options
# gcc is the default compiler
# -g is for debug
# -Wall shows all warnings
CC=      gcc
CFLAGS=  -g -Wall

# Build everything
test: $(SRC) lib
	$(CC) $(INC) $(SRC) $(CFLAGS) -o $(OBJNAME) -L. -ldyllib

$(LIB_OBJ): $(LIB_SRC) bin
	$(CC) -c $(subst bin,src,$(subst .o,.c,$@)) $(INC) $(CFLAGS) -o $@

bin:
	mkdir bin

lib: $(LIB_OBJ)
	ar rcs libdyllib.a $(LIB_OBJ)

.PHONY: clean
clean:
	rm -rf bin/
	rm $(OBJNAME)
	rm libdyllib.a
	rm *.o
	rm vgcore*
