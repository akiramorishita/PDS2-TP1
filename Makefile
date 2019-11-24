CC=g++
CFLAGS=-std=c++11 -Wall

all: main

Tree.o: Tree.h Tree.cpp
	${CC} ${CFLAGS} -c Tree.cpp

Book.o: Book.h Book.cpp
	${CC} ${CFLAGS} -c Book.cpp

main.o: Tree.h Book.h main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o Tree.o Book.o
	${CC} ${CFLAGS} main.o Tree.o Book.o -o main 

clean:
	rm -f main *.o 
