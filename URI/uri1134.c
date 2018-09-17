#include <stdio.h>

int main()
{
    int i,n,a=0,g=0,d=0;

    for(;;){
        scanf("%d",&n);
        if(n==4){
            break;
        }

        if(n<0&&n>4){
        continue;
        }

        if(n==1){
            a++;
        }
        else if(n==2){
            g++;
        }
        else if(n==3){
            d++;
        }
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n",a);
    printf("Gasolina: %d\n",g);
    printf("Diesel: %d\n",d);

    return 0;
}
