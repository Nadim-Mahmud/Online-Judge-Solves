#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll rev(ll n){
    ll x = 0;
    while(n){
        x = x*10 + n%10;
        n /= 10;
    }
    return x;
}

int main(){
    ll n,j,k,m,a,b,ts,cas=0;
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",rev(rev(n)+rev(m)));
    }
    return 0;
}
