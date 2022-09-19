#include "combine.h"


/* opens and prepares a new combined obj file */
CombinedFile* cf_initialize(CombinedFile* comb, char* name) {
    comb->fp = fopen(name, "w");
    comb->vertexOffset = 0;
    return comb;
}


/* closes the file and clears its file pointer */
void cf_close(CombinedFile *output) {
    fclose(output->fp);
    output->fp = NULL;
}


/* appends the contents of the given `objFileName` to the combined 
   object file */
void cf_append(CombinedFile *output, char* objFileName) {
    char buf[MAX_LINE_LENGTH];
    int vertexCount = 0;               /* count the vertices in this file */
    int offset = output->vertexOffset; /* get the current vertex offset */

    /* TODO: Use `fopen` to open `objFileName` for reading.
             (Declare a file pointer named `input`.) */

    /* TODO: Print a comment line: # ----- <objFileName> ----- to the output
            (use  `fprintf`) */

    /* TODO: Use `fgets` to read lines into `buf` from `input` */
    while (0) {
        if (buf[0] == 'f') { /* a face line */
            int v1, v2, v3;
            /* TODO: read the "f <v1> <v2> <v3>" from `buf` - use sscanf */

            /* TODO: print an updated "f <v1+offset> <v2+offset> <v3+offset>" to 
                    the output (use `fprintf`) */
        } else {
            if (buf[0] == 'v') { /* a vertex line */
                 vertexCount++; 
            }
            /* TODO: write the line as is to output (use `fputs`) */
        }
    }

    output->vertexOffset += vertexCount; /* update the accumulated vertex count */

    /* TODO: close in the `input` */
}

