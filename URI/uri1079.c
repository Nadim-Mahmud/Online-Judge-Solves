#include <stdio.h>

int main()
{
    int i,n;
    double x,y,z,a;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%lf %lf %lf",&x,&y,&z);

        a = (x*2+y*3+z*5)/10;
        printf("%.1lf\n",a);
    }
    return 0;
}
