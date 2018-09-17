#include <stdio.h>

int main()
{
    double i,n;
    int c=0;
    for(i=1;i<=6;i++){
        scanf("%lf",&n);
        if(n>0){
            c++;
        }
    }
    printf("%d valores positivos\n",c);
    return 0;
}

