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
using namespace std;

#define N 5009
int pr[78600],in=0;
char ap[N+3];
void siv()
{
    int i,j,sq,p;
    sq=sqrt(N)+2;
    ap[1]=1;
    for(i=2;i<sq;i++){
        if(!ap[i]){
            for(j=i*i;j<=N;j+=i)ap[j]=1;
        }
    }
    for(i=2;i<N;i++){
        if(!ap[i]){
            pr[in++]=i;
        }
    }
}

int ara[MX];
//ll ar1[MX],ar2[MX];
//char str[MX];
//char ss[MX],ss1[MX];

int mr[20000000];

int main()
{
    int i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum=0,mn=INT_MAX,mx=0,mxp=0,gcd=1;
    //freopen("test.txt","r",stdin);
    siv();
   // P(__gcd(2,2))
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%d",&ara[i]);
        if(i==1) gcd = ara[i];
        gcd = __gcd(gcd,ara[i]);
    }
    for(i=1;i<=n;i++){
        ara[i] /= gcd;
    }
   // P(gcd)
    for(i=1;i<=n;i++){
       // P(ara[i])
        for(j=0;pr[j]*pr[j]<=ara[i]&&j<in;j++){
            if(ara[i]%pr[j]==0){
                mr[pr[j]]++;
               // P()
            }
            while(ara[i]%pr[j]==0){
                ara[i] /= pr[j];
            }
        }
        //P(ara[i])
        if(ara[i]>1){
            mr[ara[i]] ++;
           // P(mr[ara[i]])
        }
    }
    mxp = mr[2];
    for(i=3;i<20000000;i+=2){
        mxp = max(mxp,mr[i]);
    }

    if(mxp)cout<<(n-mxp)<<endl;
    else puts("-1");

    return 0;
}
