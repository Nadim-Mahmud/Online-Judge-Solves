#include <stdio.h>

int main()
{
    int i,j,n,x,y;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=1;j<=2;j++){
            x =i*i+(j-1);
            y =i*i*i+(j-1);
            printf("%d %d %d\n",i,x,y);
        }

    }
    return 0;
}
