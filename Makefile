#COMPILER
GCC := gcc
FLAGS := -Wall -Werror -g

#SRC
SRC := main.c BST.c test.c
EXEC := main

all : $(EXEC)

$(EXEC) : $(SRC)
	$(GCC) $^ $(FLAGS) -o $(EXEC)

run : 
	./$(EXEC)
vlg : 
	valgrind -s ./$(EXEC)
