#include <stdio.h>

int main()
{
    int n,i,j,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        x=i;
        for(j=1;j<=3;j++){
            if(j!=1&&j<=3){
                printf(" ");
            }
            printf("%d",x);
            x=x*i;
        }
        printf("\n");
    }
    return 0;
}
