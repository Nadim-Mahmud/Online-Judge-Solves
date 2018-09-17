#include<bits/stdc++.h>
#define ll long long
#define MX 1000000
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

ll powr(ll x, ll y){

    ll res = 1;
    while (y > 0){

        if (y & 1) res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

ll sum(ll n){

    ll i,c,c1,s=1;

    for(i=1;i <= k && pr[i]*pr[i] <= n ; i++){
        c = 0;
        while(n%pr[i] == 0){
            n /= pr[i];
            c++;
        }
        if(c){
           s *= ((powr(pr[i] , c + 1) - 1) / (pr[i] - 1));
        }
        //cout<<s<<endl;
    }
   // cout<<n<<endl;
    if(n>1) s *= ((powr(n , 2) - 1) / (n - 1));
    return s;
}

int main(){

    ll t,cas = 0,i,c,x,y;
    char ch;
    sieve();

    cin>>t;
    while(++cas <= t){

        if(cas > 1) scanf(" %c",&ch);
        scanf("%lld",&x);

        c = pow(2,x-1);
        //cout<<c<<endl;
        y = (c * 2 - 1);
        c *= y;
       // cout<<x<<" "<<c<<endl;
        if(c == (sum(c)-c)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
