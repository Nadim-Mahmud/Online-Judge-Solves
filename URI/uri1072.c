#include <stdio.h>

int main()
{
    int i,n,x,c1=0,c2=0;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%d",&x);

        if(x>=10&&x<=20){
            c1++;
        }
        else{
            c2++;
        }
    }
        if(c1!=0){
            printf("%d in\n",c1);
        }
       if(c2!=0){
            printf("%d out\n",c2);
        }
        return 0;
}
