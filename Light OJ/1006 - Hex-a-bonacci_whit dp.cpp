#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll ara[10009];

ll fn( ll n ) {
    //cout<<ara[n]<<endl;
    if(ara[n] != -1){
        //cout<<ara[n]<<endl;
        return ara[n];
    }
    else return ara[n] = ( fn(n-1)+ fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))% 10000007;
}
int main() {
    ll n, caseno = 0, cases,i;
    scanf("%lld", &cases);
    while( cases-- ) {
        memset(ara,-1,sizeof(ara));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &ara[0], &ara[1], &ara[2], &ara[3], &ara[4], &ara[5], &n);
        printf("Case %lld: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
