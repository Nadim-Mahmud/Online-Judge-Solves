#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){

    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){

    ll n,sum,i,j;

    while(1){
        sum = 0;
        scanf("%lld",&n);
        if(n==0) break;

        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                sum += gcd(i,j);
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}
