#include <stdio.h>

int main()
{
    int x=1,y=60;

    for(;;){

       printf("I=%d J=%d\n",x,y);
       if(y==0){
        break;
       }
        x =x+3;
        y=y-5;
    }
    return 0;
}
