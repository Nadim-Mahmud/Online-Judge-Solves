#include <stdio.h>

int main()
{
    double x1,x2,y1,y2,a,b,r;
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    a = (x2-x1)*(x2-x1);
    b =(y2-y1)*(y2-y1);
    r = a+b;
    printf("%.4lf\n",sqrt(r));

    return 0;


}
