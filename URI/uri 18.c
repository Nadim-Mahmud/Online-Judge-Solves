#include <stdio.h>

int main()
{
    int N,h,f,tw,t,fi,two,o,x,y,z,i,j,k;

    scanf("%d",&N);
    h = N/100;
    x = N-(h*100);
    f =  x/50;
    y = x - (f*50);
    tw = y/20;
    z = y - (tw*20);
    t = z/10;
    i =  z -(t*10);
    fi = i/5;
    j = i -(fi*5);
    two = j/2;
    k = j-(two*2);
    o = k/1;

    printf("%d nota(s) de R$ 100,00\n",h);
    printf("%d nota(s) de R$ 50,00\n",f);
    printf("%d nota(s) de R$ 20,00\n",tw);
    printf("%d nota(s) de R$ 10,00\n",t);
    printf("%d nota(s) de R$ 5,00\n",fi);
    printf("%d nota(s) de R$ 2,00\n",two);
    printf("%d nota(s) de R$ 1,00\n",o);

    return 0;

}
