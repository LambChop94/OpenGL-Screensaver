# Linux (default)
LDFLAGS = -lGL -lGLU -lglut
CFLAGS=-g -Wall -std=c++11
CC=g++
EXEEXT=
RM=rm

run: A1
	./A1$(EXEXT)

A1: main.o point.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) *.o A1$(EXEEXT)