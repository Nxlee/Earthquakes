CC = gcc
CFLAGS = -std=c99 -Wall -D_POSIX_C_SOURCE -g
MAIN = myEq
OBJS = myEq.o func.o
all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

myEq.o : myEq.c 
	$(CC) $(CFLAGS) -c myEq.c

func.o : func.c func.h
	$(CC) $(CFLAGS) -c func.c

clean :
	rm *.o $(MAIN)
