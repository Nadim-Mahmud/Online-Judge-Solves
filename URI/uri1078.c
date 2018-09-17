#include <stdio.h>

int main()
{
    int i,n,x;
    scanf("%d",&n);
    for(i=1;i<=10;i++){
        x = 0;
        x =  n*i;
        printf("%d x %d = %d\n",i,n,x);
    }
    return 0;

}
