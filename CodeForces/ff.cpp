#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,ara[50][50],k;

ll rec(ll i,ll j,ll val){
    if(i<1||j<1||i>n||j>m) return 0;
    if(i==n&&j==m){
        if((val^ara[n][m])==k) return 1;
        return 0;
    }
    return rec(i+1,j,val^ara[i][j]) + rec(i,j+1,val^ara[i][j]);
}

int main(){
    ll i,j,l;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&ara[i][j]);
        }
    }
    cout<<rec(1,1,0)<<endl;
    return 0;
}
