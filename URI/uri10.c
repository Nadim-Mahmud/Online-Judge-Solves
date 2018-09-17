#include <stdio.h>

int main()
{
    int a,b,x,y;
    double c,z,t;

    scanf("%d %d %lf",&a,&b,&c);
    scanf("%d %d %lf",&x,&y,&z);
    t = c*b+z*y;

    printf("VALOR A PAGAR: R$ %.2lf\n",t);

    return 0;
}
