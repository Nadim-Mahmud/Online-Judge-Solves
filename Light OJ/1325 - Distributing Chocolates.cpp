#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
#define pii pair<int,int>
#define M 100000007
#define sq 10001
using namespace std;

ll bgm(ll n,ll p)
{
    if(n==1) return 1;
    if(p==1) return n%M;
    if(p==0) return 1;
    if(p%2==1) return (bgm(n,p-1)*n)%M;
    else{
        ll x = bgm(n,p/2);
        return (x*x)%M;
    }
}

pii extnuc(ll a,ll b)
{
    if(b==0)return pii(1,0);
    pii d=extnuc(b,a%b);
    return pii(d.second,d.first-d.second*(a/b));
}

ll modi(ll n)
{
    pii d=extnuc(n,M);
    return ((d.first%M)+M)%M;
}

int main()
{
    ll i,j,a,b,ts,cn=0,n,tmp,tmp2,ans,x,mini;
    // freopen("test.txt","r",stdin);
    scanf("%lld",&ts);
    while(ts--){
        scanf("%lld %lld",&a,&b);

        map<ll,ll>mp;
        tmp=1,ans=0;

        for(i=0;i<sq;i++){
            mp[tmp] = i;
            tmp = (tmp*a)%M;
        }

        tmp = (bgm(modi(a),sq))%M;
        //cout<<tmp<<endl;
        tmp2 = b;
        for(i=0;i<sq;i++){
            if(mp.find(tmp2) != mp.end()){
                //cout<<tmp2<<endl;
                ans = (i*sq + mp[tmp2])%M;
                //cout<<ans<<endl;
                break;
            }
            //cout<<tmp2<<endl;
            tmp2 = (tmp2*tmp)%M;
        }
        printf("Case %lld: %lld\n",++cn,ans);
    }
    return 0;
}
