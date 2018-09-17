#include<bits/stdc++.h>
#define ll long long
#define MX 300000
using namespace std;

ll h,h1,ara[35],n,cnt,w,ans,s;//A[MX],B[MX],s,av=0,bv=0;
map<ll,bool>mp;

void rec(ll ps,ll waight)
{
    if(ps>=h){
        if(s==0) mp[waight] = 1;
        else if(mp[w-waight]==1) ans=1;
        return;
    }
    rec(ps+1,waight+ara[ps]);
    rec(ps+1,(waight+2*ara[ps]));
    rec(ps+1,waight);
}


int main()
{
    ll i,j,k,a,b,ts=0,cas=0;
    //freopen("1235.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        ans=0;
        scanf("%lld %lld",&n,&w);
        for(i=0;i<n;i++){
            scanf("%lld",&ara[i]);
        }
        s=0;
        h = ceil((double)n/2.0);
        rec(0,0);
        s=1,h1 = h,h = n;
        rec(h1,0);

        if(ans) printf("Case %lld: Yes\n",cas);
        else printf("Case %lld: No\n",cas);

        mp.clear();
    }
    return 0;
}

