#include <stdio.h>

int main()
{
    int x,y,i,j,z;

    for(;;){
            scanf("%d %d",&x,&y);


    if(x>y){
        i=y;
        j=x;
    }
    else{
        i=x;
        j=y;
    }
        if(i<=0){
            break;
        }
    z=0;
    for(i;i<=j;i++){
        z=z+i;
        printf("%d ",i);
    }
     printf("Sum=%d\n",z);
    }

    return 0;
}
