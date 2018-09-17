#include <stdio.h>

int main()
{
    int i,j;
    float  x=0,y;

    for(i=1;i<=11;i++){
        for(j=1;j<=3;j++){
                y=j+x;
            printf("I=%.1f J=%.1f\n",x,y);
        }
        x=x+0.2;
    }
    return 0;
}
