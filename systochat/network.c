/*                                                                                                                                                                   
 A multi-threaded, multi-room chat server                                                                                                                            
 */

#include "systochat.h"



/* display a message to the socket and closes it */
void* shutDown(int sock, char *msg) {
  write(sock, msg, strlen(msg));
  close(sock);
  return NULL;
}


/* main loop of communication with a user socket */
void* handleUser(void *pfd) {
  int sock = *((int*) pfd);
  char buffer[1024];
  int bytesRead;
  char nickname[1024], roomname[1024];

  /* First message should be:    ":join <nickname> <roomname>"   */
  bytesRead = read(sock, buffer, 1023); buffer[bytesRead] = '\0';
  if ( sscanf(buffer, ":join %s %s\n", nickname, roomname) == 2 ) {
    if (isValidRoom(roomname)) {
      if (isNameAvailable(nickname)) {
	if (!addToRoom(nickname, roomname)) {
	  return shutDown(sock, "something unfortunate happened\n");
	}
      } else {
	return shutDown(sock, "nickname already used\n");
      }
    } else {
      /* todo: list valid rooms */
      return shutDown(sock, "unknown room\n");
    }
  } else {
    return shutDown(sock, "Please use   :join <nick> <room>\n");
   }

  
  
  while (1) {
    bytesRead = read(sock, buffer, 1023); buffer[bytesRead] = '\0';

    if (strcasecmp(buffer, ":quit\n") == 0) {
      write(sock, "bye!\n", 5);
      break;
    } else {
      write(sock, buffer, bytesRead);
    }
  }

  close(sock);
  return NULL;
}

