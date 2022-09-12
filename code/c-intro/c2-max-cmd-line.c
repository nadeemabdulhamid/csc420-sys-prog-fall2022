/* max-cmd-line.c */
/* gcc c2-max-cmd-line readlines-writelines.c p101-alloc.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 10000

int mygetline(char *s, int lim);
int interactive();
int process(char *strs[], int n);

int main(int argc, char *argv[]) 
{
    int max;
    if (argc < 2) {
        max = interactive();
    } else {
        max = process(argv+1, argc-1);
    }

    printf("%d\n", max);

    return 0;
}

int interactive() 
{
    char line[MAXLEN];
    int max = INT_MIN;

    while ( mygetline(line, MAXLEN) > 0 ) 
    {
        int val = atoi(line);
        /*printf("%d\n", val);*/
        if (val > max) { max = val; }
    }

    return max;
}

int process(char *strs[], int n)  
{
    int max = INT_MIN;

    while ( n-- > 0 ) 
    {
        int val = atoi(*strs);
        /*printf("%d\n", val);*/
        if (val > max) { max = val; }
        strs++;
    }

    return max;
}
