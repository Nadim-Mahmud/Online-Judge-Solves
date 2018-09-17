#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,ara[15];
ll dp[15][15];

ll dc(ll i,ll ds)
{
    if(ds==n) return 1;
    //if(i>m) return 0;
    if(dp[i][ds]!=-1) return dp[i][ds];
    ll ret1=0,ret2=0;
    for(int j=1;j<=m;j++){
        if(i==0||abs(ara[i]-ara[j])<=2) ret1 += dc(j,ds+1);
    }
    //if(ds==1) ret2 += dc(i+1,ds);
    return dp[i][ds] = ret1+ret2;
}

int main()
{
    ll i,j,k,cas=0,ts;
    //freopen("1122.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%lld %lld",&m,&n);
        for(i=1;i<=m;i++)
            scanf("%lld",&ara[i]);
        printf("Case %lld: %lld\n",cas,dc(0,0));
    }
    return 0;
}
