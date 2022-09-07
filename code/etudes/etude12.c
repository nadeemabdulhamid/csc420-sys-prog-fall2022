#include <stdio.h>
#define PRX         printf("x= %d \n",x)
#define PR(a)       printf("%d \n",a)
#define PR2(a,b)    printf("%d\t %d \n", a,b)
#define PR3(a,b,c)  printf("%d\t %d\t %d \n", a,b,c)

/* E12 Pre- and Post- increments */

etude12()
{
    int x = 2,  y = 1,  z = 4;
                  z += y += x ++ ;  PR3(x,y,z);         /* 12.1 */
                  z *= x += y -- ;  PR3(x,y,z);         /* 12.2 */
    x = 5;        z = x ++ - 1 ;    PR2(x,z);           /* 12.3 */
                  z = ++ x - 1 ;    PR2(x,z);           /* 12.4 */
    x = 6, y = 7; z = x += y ++ ;   PR3(x,y,z);         /* 12.5 */
                  z = x ++ + ++ y ; PR3(x,y,z);         /* 12.6 */
}


main()
{
    etude12();
}