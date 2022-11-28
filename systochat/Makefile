OBJS	= main.o network.o systochat.o
SOURCE	= main.c network.c systochat.c
HEADER	= systochat.h
OUT	= chat-server
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -pthread

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

network.o: network.c
	$(CC) $(FLAGS) network.c 

systochat.o: systochat.c
	$(CC) $(FLAGS) systochat.c 


clean:
	rm -f $(OBJS) $(OUT)
