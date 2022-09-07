#include <stdio.h>
#define PRX         printf("x= %d \n",x)
#define PR(a)       printf("%d \n",a)
#define PR2(a,b)    printf("%d\t %d \n", a,b)
#define PR3(a,b,c)  printf("%d\t %d\t %d \n", a,b,c)

/* E11 Assignment Operators */

etude11()
{
    int   w=2,  x,  y,  z=2;
    x = y = z;              PR3(x, y, z);           /* 11.1 */
    x = y == z;             PR3(x, y, z);           /* 11.2 */
    x *= 3 + 2;             PRX;                    /* 11.3 */
    x = w *= y = z = 4;     PR2(w, x); PR2(y, z);   /* 11.4 */
    x=3,  y=1,  z=4;
    x *= y + 2;             PR2(x, y);              /* 11.5 */
    x += y *= z -= 2;       PR3(x, y, z);           /* 11.6 */
}


main()
{
    etude11();
}