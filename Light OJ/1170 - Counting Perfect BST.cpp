#include<bits/stdc++.h>
#define pii pair<int,int>
#define p(XX) cout<<XX<<endl;
#define pp(XX,YY) cout<<XX<<" "<<YY<<endl;
using namespace std;

#define ll long long
#define MX 1000005
#define MD 100000007

ll powr(ll n, ll p){
    if(p==0) return 1;
    if(p==1) return n;
    if(p&1LL) return (powr(n,p-1)*n)%MD;
    else{
        ll x = powr(n,p/2)%MD;
        return (x*x)%MD;
    }
}

ll inverse(ll n){
    return (powr(n,MD-2))%MD;
}

ll ft[MX];

void fact(){
    ll i;
    ft[0] = 1;
    for(i=1;i<MX;i++){
        ft[i] = (ft[i-1]*i)%MD;
    }
}

ll nCr(ll n,ll r){
    ll x = ft[n];
    ll y = inverse((ft[r]*ft[n-r])%MD)%MD;
    return (x*y)%MD;
}

ll catalan(ll n){
    ll  x = nCr(2*n,n);
    return (x*inverse((n+1)))%MD;
}

#define MXX 10000000005
ll ara[200005],in=0;

void gen(){
    ll i,j,k,x;
    for(i=2;i<=100005;i++){
        x = i;
        while(x*i<=MXX){
            x *= i;
            ara[++in] = x;
        }
    }
}

void process(){
    ll x=in,i;
    in=1;
    for(i=1;i<=x;i++){
        if(ara[in]!=ara[i]){
            ara[++in] = ara[i];
        }
    }
}

ll upper(ll n){
    ll lw=1,hi=in,mid,i;
    while(hi-lw>5){
        mid = (lw+hi)/2;
        if(ara[mid]>n) hi = mid-1;
        else lw = mid;
    }
    for(i=lw;i<=hi;i++){
        if(ara[i]>=n||i+1>in){
            break;
        }
    }
    return i;
}

ll lower(ll n){
    ll  lw=1,hi=in,mid,i;
    while(hi-lw>5){
        mid = (lw+hi)/2;
        if(ara[mid]>n) hi = mid-1;
        else lw = mid;
    }
    for(i=lw;i<=hi;i++){
        if(ara[i+1]>n||i+1>in){
            break;
        }
    }
    return i;
}


int main(){
    fact();
    gen();
    sort(ara+1,ara+in+1);
    process();
    ll i,j,k,a,b,n,m,ts,cas=0,ub,lb,ans;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&a,&b);
        ub = upper(a);
        lb = lower(b);
        ans = lb - ub + 1;
        if(b<ara[1]||a>ara[in]) ans = 0;
        if(ans!=0){
            ans = catalan(ans);
        }
        printf("Case %lld: %lld\n",cas,ans);
    }

}



