#include<bits/stdc++.h>

using namespace std;

int ara[200],u[200],k;

void per(int a,int n){
    int i;
    if(a==n+1){
        k--;
        for(i=65;i<=n;i++) printf("%c",ara[i]);
        printf("\n");
        return ;
    }
    for(i=65;i<=n;i++) if(!u[i]){
        u[i] = 1;
        ara[a] = i;
        if(k<=0) break;
        per(a+1,n);
        u[i] = 0;
    }
}

int main(){

    int cas=0,t,a,i;
    cin>>t;
    while(++cas<=t){
        scanf("%d %d",&a,&k);

        for(i=1;i<=199;i++){

            ara[i]=0;
            u[i]=0;
        }
        printf("Case %d:\n",cas);
        per(65,64+a);
    }
    return 0;
}
