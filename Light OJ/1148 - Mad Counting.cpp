#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int ara[1000005],a[100];

int main(){

    int n,c,sum,s,t,i,cas=0,ans,j,m;

    scanf("%d",&t);
    while(++cas <= t){
        ans = 0;
        m=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            if(ara[m]==0) ans+=m+1;
            ara[m]++;
            //cout<<ara[m]<<endl;
            if(ara[m]>m) ara[m] = 0;
            a[i] = m;
        }
        printf("Case %d: %d\n",cas,ans);
        for(i=1;i<=n;i++){
            ara[a[i]]=0;
        }
    }
    return 0;
}
