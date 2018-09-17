#include <stdio.h>

int main()
{
    int N,y,m,d,x;

    scanf("%d",&N);

    y=N/365;
    x=N%365;
    m=x/30;
    d=x%30;

    printf("%d ano(s)\n",y);
    printf("%d mes(es)\n",m);
    printf("%d dia(s)\n",d);

    return 0;
}

