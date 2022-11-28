/*
 A multi-threaded, multi-room chat server
 */

#include "systochat.h"

User *userList[MAX_USERS];
Room *roomList;


int main() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0); // TCP connection - stream
  if (server_socket == -1) {
    printf("Error creating socket.\n");
    return 1;
  }

  int on = 1;  // set the 'reuse address' socket option
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

  // prepare the sockaddr_in structure
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 8124 );

  if (bind(server_socket, (struct sockaddr*)&server, sizeof(server))  < 0) {
    printf("Bind failed\n");
    return 1;
  }

  listen(server_socket, 5);

  // accept incoming connections
  printf("Waiting for incoming connections...\n");
  while (1) {
    struct sockaddr_in client;
    int new_socket;
    int sz = sizeof(struct sockaddr_in);
    if ((new_socket = accept(server_socket, (struct sockaddr *) &client,
			     (socklen_t*)&sz))  != -1) { // successful connection
      // start talking...
      pthread_t thread;
      pthread_create(&thread, NULL, handleUser, &new_socket);
    }
  }

  return 0;
}
