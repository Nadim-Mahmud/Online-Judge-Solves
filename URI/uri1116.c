#include <stdio.h>

int main()
{
    int i,n;
    double x,y,z;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

            scanf("%lf %lf",&x,&y);

        if(y==0){
            printf("divisao impossivel\n");
        }
        else{
            z=x/y;
            printf("%.1lf\n",z);
        }
    }

    return 0;
}
