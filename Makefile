
CC = gcc
LDLIBS =  -lglut -lGL -lGLU -lm

OBJS = init.o display.o pend.o reshape.o

all : pendpoc tags

pendpoc : main.o $(OBJS)
	$(CC) $(CFLAGS) main.o $(OBJS) -o pendpoc $(LDLIBS)

main.o : main.cc 
	$(CC) $(CFLAGS) main.cc -c
init.o :
	$(CC) $(CFLAGS) init.cc -c
display.o :
	$(CC) $(CFLAGS) display.cc -c
pend.o :
	$(CC) $(CFLAGS) pend.c -c
reshape.o :
	$(CC) $(CFLAGS) reshape.cc -c

clean :
	rm *.o

pristine :
	rm *.o
	touch *

tags :
	ctags *.h *.cc

