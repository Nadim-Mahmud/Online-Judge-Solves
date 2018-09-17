#include<bits/stdc++.h>
#define ll long long
#define MX 100000
using namespace std;

int pr[MX+5],k=0;

void sieve(){

    int i,j,r=sqrt(MX);

    pr[++k] = 2;

    for(i = 3;i <= MX;i += 2){
        if(pr[i]==0){
            pr[++k] = i;
            if(i<=r){
                for(j=i*i ; j <= MX ; j += i<<1){
                    pr[j] = 1;
                }
            }
        }
    }
}

ll primef(ll n){

    ll mul = 1,c,i;
    for(i = 1; i<=k && pr[i]*pr[i] <= n ;i++){
        c = 1;
        while(n%pr[i]==0){

            n /= pr[i];
            c++;
        }
        mul = mul * c;
    }
    if(n>1) mul = mul*2;
    return mul;
}

int main(){

    ll t,cas = 0,x,y,l,i,j,c,mx,p,n;
    sieve();
    cin>>t;
    while(++cas <= t){

        scanf("%lld %lld",&x,&y);
        mx = 0;
        for(j=x;j<=y;j++){
            p = primef(j);
            if(p>mx) mx = p , l = j;
        }

        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",x,y,l,mx);
    }
    return 0;
}
