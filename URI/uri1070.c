#include <stdio.h>

int  main()
{
    int  i,x;

    scanf("%d",&x);
    if(x%2==0){
        x=x+1;
    }
    for(i=1;i<=6;i++){
        printf("%d\n",x);
        x=x+2;
    }
    return 0;
}
