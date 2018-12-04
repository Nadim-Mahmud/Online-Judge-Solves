#include <bits/stdc++.h>
#define ll unsigned long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
#define MX 100000015
using namespace std;

#define check(X) (mkr[X>>6]&(1<<((X&63)>>1)))
#define mark(X) mkr[X>>6]|=(1<<((X&63)>>1))
int mkr[100009000/64],SZ=100000020;
ll pr[7000000],in=0;

void bitwsiv()
{
    int i,j,rt=sqrt(SZ)+1;
    for(i=3; i<=rt; i+=2){
        if(!check(i)){
            for(j=i*i; j<=SZ; j+=i<<1){
                mark(j);
            }
        }
    }
    pr[++in]=2;
    for(i=3; i<=SZ; i+=2){
        if(!check(i))pr[++in]=i;
    }
}

ll sod(ll n){
    ll i,ans = 1,cn,mr;
    for(i=1;i<=in&&pr[i]*pr[i]<=n;i++){
        cn = pr[i];
        mr=0;
        while(n%pr[i]==0){
            n /= pr[i];
            cn *= pr[i];
            mr=1;
        }
        if(mr) ans *= (cn-1)/(pr[i]-1);
    }
    if(n>1){
        ans *= n+1;
    }
    return ans;
}



int main()
{
    bitwsiv();
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum=0,mn=INT_MAX,mx=0;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%llu",&n);
        x = sod(n);
        x -= n;
        printf("%llu\n",x);
    }
    return 0;
}
