#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll n,sum;

    while(1){

        scanf("%lld",&n);
        if(n<0) break;

        n = ((n+1)*n)/2;

        printf("%lld\n",n+1);
    }
    return 0;
}
