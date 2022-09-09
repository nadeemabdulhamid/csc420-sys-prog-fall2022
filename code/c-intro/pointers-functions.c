#include <stdio.h>

void f(int x, int y);
void g(int *xp, int *yp);

int main() {
    int x, y;

    x = 52;
    y = 91;

    printf("%d %d\n", x, y);
    
    f(x, y);
    printf("%d %d\n", x, y);

    g(&x, &y);
    printf("%d %d\n", x, y);
}

void f(int x, int y) {
    x = 70;
    y = 15;
}

void g(int *xp, int *yp) {
    int x = *xp;
    int y = *yp;

    x = 83;
    y = 27;

    *xp = 62;
    *yp = 18;
}
