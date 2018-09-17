#include <stdio.h>

int main()
{
    int i,j=1,n,x=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
            x=x+j;
        for(j=x;j<=x+2;j++){
            printf("%d ",j);
        }
        x=1;
        printf("PUM\n");
    }
    return 0;
}
