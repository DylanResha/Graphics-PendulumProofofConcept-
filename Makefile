
CC = gcc
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = includes.h globals.h
OBJS = init.o display.o pend.o reshape.o

all : pendpoc tags

pendpoc : main.o $(OBJS)
	$(CC) $(CFLAGS) main.o $(OBJS) -o pendpoc $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

display.o : display.cc $(HEADERS)
	$(CC) $(CFLAGS) display.cc -c

pend.o : pend.c $(HEADERS)
	$(CC) $(CFLAGS) pend.c -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(CFLAGS) reshape.cc -c


clean :
	rm *.o

pristine :
	rm *.o
	touch *

tags :
	ctags *.h *.cc *.c

