#include <stdio.h>

int main()
{
    int x ,y;
    for(;;){

        scanf("%d %d",&x,&y);

        if(x==y){
            break;
        }
        if(y>x){
            printf("Crescente\n");
        }
        else{
            printf("Decrescente\n");
        }
    }
        return 0;

}
