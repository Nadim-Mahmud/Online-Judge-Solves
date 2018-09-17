#include <stdio.h>

int main()
{
    int x,y,i,j,z=0;

    scanf("%d %d",&x,&y);

    if(x>y){
        i=y;
        j=x;
    }
    else{
        i=x;
        j=y;
    }
    for(i=i+1;i<j;i++){
                if(i%2==0){
                }
                else{
                    z=z+i;
                }
    }
    printf("%d\n",z);

    return 0;

}
