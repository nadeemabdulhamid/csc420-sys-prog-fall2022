#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

/* represents the object file to which other files are being appended */
typedef struct {
    FILE *fp;
    int vertexOffset;
} CombinedFile;

/* opens and prepares a new combined obj file */
CombinedFile* cf_initialize(CombinedFile* comb, char* name);

/* closes the file and clears its file pointer */
void cf_close(CombinedFile *output);

/* appends the contents of the given `objFileName` to the combined object file */
void cf_append(CombinedFile *output, char* objFileName);


