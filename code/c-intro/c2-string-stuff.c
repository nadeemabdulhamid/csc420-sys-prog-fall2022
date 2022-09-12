/* string-stuff.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

int my_strlen(const char *str) 
{
	const char *s;

	for (s = str; *s; ++s);
	return(s - str);
}

// Function to implement `strcat()` function in C
char* my_strcat(char* destination, const char* source)
{
    // make `ptr` point to the end of the destination string
    char* ptr = destination + my_strlen(destination);
 
    // appends characters of the source to the destination string
    while (*source != '\0') {
        *ptr++ = *source++;
    }
 
    // null terminate destination string
    *ptr = '\0';
 
    // the destination is returned by standard `strcat()`
    return destination;
}
 
// Implement `strcat()` function in C
int main()
{
    char str[100] = { 0 };
 
    my_strcat(str, "Berry ");
    my_strcat(str, "College ");
    my_strcat(str, "– ");
    my_strcat(str, "The ");
    my_strcat(str, "world's ");
    my_strcat(str, "largest ");
    my_strcat(str, "campus");
 
    puts(str);
 
    return 0;
}
