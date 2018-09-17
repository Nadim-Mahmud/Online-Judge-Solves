#include <stdio.h>

int main()
{
    int i,j=2,x;

    for(i=1;i<=9;i=i+2){
        x=j+5;
        for(j=x;j>x-3;j=j-1){
            printf("I=%d J=%d\n",i,j);
        }
    }
    return 0;
}

