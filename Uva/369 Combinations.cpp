#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[105][105];

ll comb(ll n,ll r){

    if(n==r) return 1;
    if(r==1) return n;

    if(dp[n][r] != -1) return dp[n][r];
    else return dp[n][r] = comb(n-1,r-1) + comb(n-1,r);
}


int main(){

    ll n,r;

    while(1){
        scanf("%lld %lld",&n,&r);
        if(n==0&&r==0) break;

        memset(dp,-1,sizeof(dp));
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,r,comb(n,r));
    }

    return 0;
}
