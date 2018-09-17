#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d",&n);
    x=2;
    for(;;){

         if(x>10000){
            break;
         }
        printf("%d\n",x);
        x=x+n;
    }
    return 0;
}
