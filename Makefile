CFLAGS=-g -W -Wall
OBJECTS=main.o pieces.o board.o

main: main.o pieces.o board.o
	g++ -g -o $@ $^

main.o:  main.cpp pieces.h board.h
pieces.o: pieces.h pieces.cpp
board.o: board.h pieces.h board.cpp


clean:
	rm -f $(OBJECTS)