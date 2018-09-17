#include <stdio.h>

int main()
{
    int a,b,c,t,i,mid;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&a,&b,&c);

        if(a>b&&b>c||c>b&&b>a) mid =b;
        if(b>a&&a>c||c>a&&a>b) mid =a;
        if(a>c&&c>b||b>c&&c>a) mid =c;

        printf("Case %d: %d\n",i,mid);

    }

    return 0;

}
