#include <stdio.h>

int main()
{
    int N,h,m,s,x;

    scanf("%d",&N);

    x=N/ 60 ;
    s=N%60 ;
    h=x/60;
    m=x%60 ;
    printf("%d:%d:%d\n",h,m,s);

    return 0;
}
