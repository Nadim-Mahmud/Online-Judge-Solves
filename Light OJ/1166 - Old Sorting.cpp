#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int cas=0,t,ara[150],i,j,c,tmp,n;
    scanf("%d",&t);

    while(++cas <= t){

        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        c = 0;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(ara[i] != i){
                    if(ara[j] == i){
                        tmp = ara[i];
                        ara[i] = ara[j];
                        ara[j] = tmp;
                        c++;
                    }
                }
            }
        }

        printf("Case %d: %d\n",cas,c);
    }
    return 0;
}
