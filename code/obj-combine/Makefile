OBJS	= combine.o main.o
SOURCE	= combine.c main.c
HEADER	= combine.h
OUT	= combine
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

combine.o: combine.c
	$(CC) $(FLAGS) combine.c 

main.o: main.c
	$(CC) $(FLAGS) main.c 


clean_objs:
	rm -f $(OBJS)

clean:
	rm -f $(OBJS) $(OUT)
