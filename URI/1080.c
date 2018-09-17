#include <stdio.h>

int main()

{
    int a[105],i,j,c=0,mx;

    for(i=0;i<100;i++){
        scanf("%d",&a[i]);
    }
     mx=a[0];
    for(i=0;i<100;i++){
            if(a[i]>mx){
                mx=a[i];
                c=i+1;
            }
    }
    printf("%d\n",mx);
    printf("%d\n",c);

    return 0;
}
