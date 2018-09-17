#include <stdio.h>

int main()
{
    int X;
    double Y,K;
    scanf("%d",&X);
    scanf("%lf",&Y);
    K = X/Y;

    printf("%.3lf km/l\n",K);
    return 0;
}
