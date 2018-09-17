#include <stdio.h>

int main()

{
    int a,b,c,x,y,z,mx,min,mid;
    scanf("%d %d %d",&x,&y,&z);
    a=x;
    b=y;
    c=z;
    mx=x;
    if(y>mx){
        mx=y;
    }
    if(z>mx){
        mx=z;
    }

    min=x;
    if(y<min){
        min=y;
    }
    if(z<min){
        min=z;
    }


    if(x<mx&&x>min){
        mid=x;
    }
    else if(y<mx&&y>min){
        mid=y;
    }
    else{
        mid=z;
    }

    printf("%d\n",min);
    printf("%d\n",mid);
    printf("%d\n",mx);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);

    return 0;
}
