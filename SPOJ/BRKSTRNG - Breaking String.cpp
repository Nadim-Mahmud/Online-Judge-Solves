#include<bits/stdc++.h>
#define ll long long
using namespace std;


///Unsolved


ll ara[10000];

ll bns(ll lw,ll hi){
    ll mid,tr=(ara[hi]+ara[lw])/2,x,y,z;
    while(hi-lw>4){
        mid = (hi+lw)/2;
        //cout<<lw<<" "<<hi<<" "<<mid<<endl;
        if(tr>ara[mid]) lw = mid;
        else hi = mid;
    }
    x = abs(tr-ara[lw]);
    y = lw;
    for(lw;lw<=hi;lw++){
        z = abs(tr-ara[lw]);
        if(z<x){
            x = z;
            y = lw;
        }
    }
    return y;
}


ll solve(ll lw, ll hi){
    if(hi-lw<=1) return 0;
    ll mid = bns(lw,hi);
   // cout<<lw<<" "<<hi<<" "<<mid<<endl;
    ll x = solve(lw,mid);
    if(lw==mid) mid ++;
    return (ara[hi] - ara[lw]) + x + solve(mid,hi);
}


int main(){
    ll i,j,k,n,m;
//
//    ara[1] = 0;
//    ara[2] = 3;
//    ara[3] = 8;
//    ara[4] = 10;
//    ara[5] = 20;
//   // cout<<bns(1,4);

    while(scanf("%lld %lld",&n,&m)==2){
        for(i=2;i<=m+1;i++){
            scanf("%lld",&ara[i]);
        }
        ara[1] = 0;
        ara[m+2] = n;
        printf("%lld\n",solve(1,m+2));
    }
    return 0;
}
