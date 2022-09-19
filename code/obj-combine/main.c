#include "combine.h"

int main(int argc, char const *argv[]) {
    CombinedFile *comb = (CombinedFile*) malloc(sizeof(CombinedFile));

    cf_initialize(comb, "combine.obj"); 
    cf_append(comb, "cow.obj");
    cf_append(comb, "teapot.obj");
    cf_append(comb, "pumpkin.obj");
    cf_close(comb);

    cf_initialize(comb, "combine2.obj");
    cf_append(comb, "pumpkin.obj");
    cf_append(comb, "teddy.obj");
    cf_close(comb);

    return 0;
}
