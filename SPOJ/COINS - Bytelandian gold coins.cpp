#include<bits/stdc++.h>
using namespace std;
#define MX 10000005
#define ll long long

ll dp[MX];

ll solve(ll n){
    if((n/2+n/3+n/4)<=n) return n;
    if(n<MX)
        if(dp[n]!=0) return dp[n];
    return dp[n] = solve(n/2) + solve(n/3) + solve(n/4);
}

int main(){
    int n,ts;

//    for(int i=1;i<=100;i++){
//        if(i!=solve(i)) cout<<i<<" = "<<solve(i)<<endl;
//    }

    while(scanf("%d",&n)==1){
        printf("%lld\n",solve(n));
    }
    return 0;
}

