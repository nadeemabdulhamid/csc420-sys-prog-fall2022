#include "combine.h"

/* appends the contents of the given `objFileName` to the combined 
   object file */
void cf_append(CombinedFile *output, char* objFileName) {
    char buf[MAX_LINE_LENGTH];
    int vertexCount = 0;
    int offset = output->vertexOffset;
    FILE* input = fopen(objFileName, "r");
    
    fprintf(output->fp, "# ----- %s -----\n", objFileName);

    while (fgets(buf, MAX_LINE_LENGTH, input) != NULL) {
        if (buf[0] == 'f') {
            int v1, v2, v3;
            sscanf(buf, "f %d %d %d", &v1, &v2, &v3);
            fprintf(output->fp, "f %d %d %d\n", v1+offset, 
                                v2+offset, v3+offset);
        } else {
            if (buf[0] == 'v') { vertexCount++; }
            fputs(buf, output->fp);
        }
    }

    output->vertexOffset += vertexCount;

    fclose(input);
}

/* closes the file and clears its file pointer */
void cf_close(CombinedFile *output) {
    fclose(output->fp);
    output->fp = NULL;
}

/* opens and prepares a new combined obj file */
CombinedFile* cf_initialize(CombinedFile* comb, char* name) {
    comb->fp = fopen(name, "w");
    comb->vertexOffset = 0;
    return comb;
}