#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[35][35];

ll ncr(ll n,ll r){
    if(r==1) return n;
    if(n==r) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = ncr(n-1,r) + ncr(n-1,r-1);
}


int main(){
    ll ts,cas=0,j,mul,n,k,ans,i;
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&n,&k);
        memset(dp,-1,sizeof dp);
        if(k==0) ans = 1;
        else if(n<k) ans = 0;
        else{
            ll ml=1;
            for(i=n-k+1;i<=n;i++){
                ml *= i;
                //cout<<ml<<endl;
            }
            //cout<<ml<<endl;
            ans = ml*ncr(n,k);
        }
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
