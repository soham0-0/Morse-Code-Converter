OBJS = main.cpp

CC = g++

COMPILER_FLAGS = -w

OBJ_NAME = morseconverter

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
