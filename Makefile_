CC=g++
CFLAGS=-std=c++11 -Wall

all: main teste

Tree.o: Tree.h Tree.cpp
	${CC} ${CFLAGS} -c Tree.cpp

Book.o: Book.h Book.cpp
	${CC} ${CFLAGS} -c Book.cpp

main.o: Tree.h Book.h main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o Tree.o Book.o
	${CC} ${CFLAGS} main.o Tree.o Book.o -o main 

teste.o: Tree.h Book.h teste.cpp
	${CC} -c teste.cpp

teste: teste.o Tree.o Book.o
	${CC} teste.o Tree.o Book.o -o teste

clean:
	rm -f main *.o 