#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int BUFFER_SIZE = 100;
const char prompt[20] = "Enter a new line: ";

int main(int argc, char** argv) {
  // allocate a character array of size BUFFER_SIZE
  char buf[BUFFER_SIZE];
  // loop until the program breaks out of the loop
  while (1) {
    // print the prompt
    printf(prompt);
    // this will clear standard output
    if (fflush(stdout) != 0) {
      perror("fflush");
      exit(1);
    }

    // intialize the buffer to all 0s
    memset(buf, 0, BUFFER_SIZE);
    // use fgets to read from standard input
    if (fgets(buf, BUFFER_SIZE, stdin) == NULL) {
      break;
    }

    // Tokenize input string based on strings that separated by
    // Note that strtok automatically null-terminates the tokens it finds
    // %lu will format the first agrument (the length) as an unsigned long
    printf("Read %lu Characters\n [", strlen(buf));
    char* token = strtok(buf, ", \n");
    for (int i = 0; token != NULL; i++) {
      printf("(%d) %s, ", i, token);
      token = strtok(NULL, ", \n");
    }
    printf("]\n\n");
  }
}