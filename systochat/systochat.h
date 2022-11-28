
#include <sys/socket.h>
#include <arpa/inet.h>  // inet_addr

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h> 
#include <stdbool.h>
#include <stdlib.h>

#define MAX_USERS 500
#define MAX_PER_ROOM 50

typedef struct {
  char *name;
  int sock;
} User;

typedef struct {
  char *name;
  User *members[MAX_PER_ROOM];
} Room;

extern User *userList[MAX_USERS];
extern Room *roomList;




/* ROOM HANDLING FUNCTIONS */

/* create the initial set of rooms */
void setupRooms();

/* is the given name a valid room name */
bool isValidRoom(char *name);

/* is the given name a valid, unused already nick name */
bool isNameAvailable(char *nick);

/* moves the given user into the given room
   returns if successfully done
*/
bool addToRoom(char *nick, char *room);



/* SOCKET COMMUNICATION HANDLING FUNCTIONS */

/* display a message to the socket and closes it */
void* shutDown(int sock, char *msg);

/* main loop of communication with a user socket */
void* handleUser(void *pfd);



