#include<stdio.h>

int main(){

    int r,n,x,i;
    for(i=1;;i++){
        scanf("%d %d",&r,&n);

        if(r==0) break;

        if(r <= n + (n*26)){

            printf("Case %d: %d\n",i,(r-1)/n);
        }
        else printf("Case %d: impossible\n",i);

        }

    return 0;
}
