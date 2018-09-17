#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
using namespace std;
long long H( int n );
ll hr(ll n)
{
    ll i,j,k,sum=0,ex,pr;
    for(i=1;i*i<=n;i++){
        pr = n/i;
        if(pr==i) ex = 0;
        else ex = (pr-n/(i+1))*i;
        sum += pr + ex;
    }
    return sum;
}

int main()
{
    ll i,j,a,b,ts,cas=0,n;
   // freopen("test.txt","r",stdin);
    scanf("%lld",&ts);
    while(++cas<=ts){
        scanf("%lld",&n);
        //cout<<"dd "<<H(n)<<endl;
        printf("Case %lld: %lld\n",cas,hr(n));
    }
    return 0;
}

/*
long long H( int n ) {
    long long res = 0;
    for( int i = 1; i <= n; i++ ){
        res = res + n / i;
       // cout<<n/i<<endl;
    }
    return res;
}
*/
