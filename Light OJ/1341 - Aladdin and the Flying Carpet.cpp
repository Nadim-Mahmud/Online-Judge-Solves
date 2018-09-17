#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
using namespace std;
#define N 1000009
int pr[78600],in=0;
bool ap[N+3];
void siv()
{
    int i,j,sq,p;
    sq=sqrt(N)+2;
    ap[1]=1;
    for(i=2;i<sq;i++){
        if(!ap[i]){
            for(j=i*i;j<N;j+=i)ap[j]=1;
        }
    }
    for(i=2;i<N;i++){
        if(!ap[i]){
            pr[++in]=i;
        }
    }
}

ll bf(ll n,ll b);
ll soluiton(ll a,ll b);

int main()
{
    ll i,j,a,b,ts,cn=0,n,c=0,ans;
    siv();
    //freopen("test.txt","r",stdin);
    scanf("%lld",&ts);
    while(ts--){
        ans=1,c=0;
        scanf("%lld %lld",&a,&b);
        cout<<"sulo: "<<soluiton(a,b)<<endl<<endl;
        ans = bf(a,b);
        printf("Case %lld: %lld\n",++cn,ans);
    }
    return 0;
}

ll bf(ll n,ll b){
    cout<<"div ==\n";
    ll sq, c=0;
    sq = sqrt(n);
    for(int i=b;i<=sq;i++){
        if(n%i==0&&i*i!=n) c++,cout<<i<<endl;
    }
    return c;
}

ll soluiton(ll a,ll b)
{
    int i,ans=1,c,c1=0,tmp;
    while(a%b!=0) b++;
    cout<<b<<":::"<<endl;
    if(b*b<=a)
    for(i=1;pr[i]*pr[i]<=a&&i<=in;i++){
        c=1,tmp=1;
        if(a%pr[i]==0){
            while(tmp<b){
                c1++;
                tmp *= pr[i];
            }
        }
        while(a%pr[i]==0){
            //cout<<pr[i]<<endl;
            c++;
            a /= pr[i];
        }
    }
    if(a>2) ans *= 2;

    return ans;
}
