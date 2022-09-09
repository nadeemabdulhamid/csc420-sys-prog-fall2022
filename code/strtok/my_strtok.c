#include "my_strtok.h"
#include <string.h>
/*
 * my_strtok - abbreviated from "string tokenize".
 *
 * TODO
 * In this function you should:
 * 1) use strspn to find the beginning of the token
 * - hint: think about the case where every character in the string is a delim char
 * 2) use strcspn to find the end of the token
 * 3) set the end of the token to '\0' -- think about why?
 * 4) set saved_str to point to after the token
 * 5) return a pointer to the token
 *
 * The strtok() function parses a string into a sequence of tokens.
 * On the first call to strtok() the string to be parsed should be
 * specified in str. In each subsequent call that should parse the
 * same string, str should be NULL.
 *
 * Example:
 * 	char str[20] = ",,a,b,,,cd,,";
 * 	char *t1 = strtok(str, ",");  // t1 should point to the token "a"
 * 	char *t2 = strtok(NULL, ","); // t2 should point to the token "b"
 * 	char *t3 = strtok(NULL, ","); // t3 should point to the token starting
 *                                   at "c" (the entire token is "cd")
 *  char *t4 = strtok(NULL, ","); // t4 should point to NULL
 *
 * Arguments: str - the string to be parsed, NULL to continue parsing the
 *            previous string
 *            delim - a set of characters that should tokenize up the string
 * Return value: a pointer to the next token or NULL if there are no more tokens
 */
char* my_strtok(char* str, const char* delim) {
  //   represents the suffix of the first inputted str
  //   which we'll be searching for tokens in
  static char* saved_str;

  //	if we're not reusing the string from a previous call
  //  set the saved_str to the str that's been passed in
  if (str != NULL) {
    saved_str = str;
  }

  // TODO: fill in this function

  return NULL;
}
