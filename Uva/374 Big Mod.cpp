#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod(ll n,ll p,ll m){
    ll x=1;
    while(p>0){

        if(p&1) x = (x * n) % m;
        p = p>>1;
        n = (n * n) % m;
    }
    return x;
}

int main(){

    ll n,p,m;

    while(scanf("%lld %lld %lld",&n,&p,&m)==3){

        printf("%lld\n",mod(n,p,m));
    }

    return 0;
}
