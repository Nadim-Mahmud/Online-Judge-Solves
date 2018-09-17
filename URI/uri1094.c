#include <stdio.h>

int main()
{
    int c=0,r=0,s=0,x,i,n,t,z;
    char ch;
    double a,b,y;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %c",&x,&ch);

        if(ch=='C'){
            c=c+x;
        }
        else if(ch=='R'){
            r=r+x;
        }
        else if(ch=='S'){
            s=s+x;
        }
    }
    z=c+r+s;
    printf("Total: %d cobaias\n",z);
    printf("Total de coelhos: %d\n",c);
    printf("Total de ratos: %d\n",r);
    printf("Total de sapos: %d\n",s);

    a = (double) c/z;
    b = (double) r/z;
    y = (double) s/z;
    printf("Percentual de coelhos: %.2lf %%\n",a*100);
    printf("Percentual de ratos: %.2lf %%\n",b*100);
    printf("Percentual de sapos: %.2lf %%\n",y*100);

    return 0;

}
