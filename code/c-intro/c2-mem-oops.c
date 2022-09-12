/* mem-oops.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

int* primes() {
    int p[5] = { 2, 3, 5, 7, 11 };
    for (int i = 0; i < 5; i++) { printf("> %d ", p[i]); } 
    printf("\n");
    return p;
}


int main() {
    char *s;
    strcpy(s, "hello");

    int* prs = primes();
    for (int i = 0; i < 5; i++) { printf("%d ", prs[i]); } 
    printf("\n");
}
