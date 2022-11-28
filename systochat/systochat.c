/*
 A multi-threaded, multi-room chat server
 */

#include "systochat.h"



/* create the initial set of rooms */
void setupRooms() {
  char *rooms[4] = { "study", "general", "help", "party" };
  roomList = (Room*) calloc(4, sizeof(Room));
  for (int i = 0; i < 4; i++) {
    roomList[i].name = (char*) malloc( sizeof(char) * (strlen(rooms[i]) + 1) );
    strcpy(roomList[i].name,  rooms[i]);
    for (int j = 0; j < MAX_PER_ROOM; j++) {
      roomList[i].members[j] = NULL;
    }
  }
}



/* is the given name a valid room name */
bool isValidRoom(char *name) {
  if (strcasecmp(name, "study") == 0 || strcasecmp(name, "general") == 0) return true;
  return false;
}




/* is the given name a valid, unused already nick name */
bool isNameAvailable(char *nick) {
  return true;
}




/* moves the given user into the given room
   returns if successfully done
*/
bool addToRoom(char *nick, char *room) {
  
  return true;
}




