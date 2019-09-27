# Name of binary
OBJNAME= dylibtest

# Input files
# Default is all c files in the src directory
SRC= $(wildcard src/*.c)

# Library locations for headers
# Default is headers folder
INC= -Iheaders

# Compile options
# gcc is the default compiler
# -g is for debug
# -Wall shows all warnings
CC= gcc
CFLAGS= -g -Wall

# Build everything
test: $(SRC)
	$(CC) $(INC) $(SRC) $(CFLAGS) -o $(OBJNAME)
