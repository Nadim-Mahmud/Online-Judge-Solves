#include <bits/stdc++.h>
#define ll long long
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
#define MX 1000005
#define M 1000000007
using namespace std;


#define SZ 5009
int pr[700],in=0;
bool mr[SZ+3];

void sieve(){
    int i,j,sq,p;
    sq=sqrt(SZ)+2;
    for(i=3; i<sq; i+=2){
        if(!mr[i]){
            for(j=i*i; j<=SZ; j+=i<<1){
                mr[j]=1;
            }
        }
    }
    pr[++in] = 2;
    for(i=3; i<SZ; i+=2){
        if(!mr[i]){
            pr[++in] = i;
        }
    }
}

ll ara[600];

void mult(){
    int i;
    ara[0] = 1;
    for(i=1;i<=550;i++){
        ara[i] = ara[i-1]*(pr[i]-1);
        ara[i] %= M;
        //P(ara[i]);
    }
}

int main()
{
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum=0,mn=INT_MAX,mx=0,k,p;
    //freopen("test.txt","r",stdin);
    sieve();
    mult();


    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&k,&p);


        //printf("Case %lld: \n",cas,);
    }
    return 0;
}
