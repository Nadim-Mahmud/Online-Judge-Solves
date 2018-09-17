#include <bits/stdc++.h>
#define ll long long
#define p(X) cout<<"db "<<X<<endl;
#define pp(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
using namespace std;

int pow(int n,int p){
    if(p==1) return n;
    if(p==0) return 1;
    if(p%2==1) return pow(n,p-1)*n;
    else{
        int x = pow(n,p/2);
        return x*x;
    }
}

int main()
{
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum,ara[20],lcm,ans;
    //freopen("test.txt","r",stdin);
    scanf("%lld",&ts);
    while(++cas<=ts){
        ans=0;
        scanf("%lld %lld",&n,&m);
        for(i=0;i<m;i++){
            scanf("%lld",&ara[i]);
        }
        x = pow(2,m);
        for(i=1;i<x;i++){
            j=cn=0;
            lcm=1;
            while(j<m){
                if(chk(i,j)){
                    lcm = ara[j]/__gcd(ara[j],lcm)*lcm;
                    cn++;
                }
                j++;
            }
            if(cn&1) ans += n/lcm;
            else ans -= n/lcm;
        }
        printf("Case %lld: %lld\n",cas,(n-ans));
    }
    return 0;
}
