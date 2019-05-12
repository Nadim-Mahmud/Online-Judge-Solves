#include<bits/stdc++.h>
#define ll long long
#define p(XX) cout<<XX<<endl;
#define pp(XX,YY) cout<<XX<<" "<<YY<<endl;
using namespace std;
#define MX 1000000000005LL
ll ara[1000006],in=0,prin;

void sumgen(ll n){
    if(n>MX) return;
    if(n!=0) ara[++in] = n;
    sumgen(n*10+4);
    sumgen(n*10+7);
}

void mulgen(ll n,ll l){
    if(n>MX||n<0) return;
    if(n!=1) ara[++in] = n;
    for(int i=l;i<=prin;i++){
        if(n*ara[i]>0&&n*ara[i]<MX) mulgen(n*ara[i],i);
        else break;
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

//8346
int main(){
    ll i,j,k,l,m,n,a,b,c,d,x,y,cas=0,ts,lb,ub,ans;

    //freopen("test.txt","r",stdin);

    sumgen(0);
    prin = in;
    sort(ara+1,ara+in+1);
    mulgen(1,1);
    sort(ara+1,ara+in+1);
    process();
    //p(in)
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&a,&b);
        ub = upper(a);
        lb = lower(b);
        ans = lb - ub + 1;
        if(b<ara[1]||a>ara[in]) ans = 0;
        printf("Case %lld: %lld\n",cas,ans);
    }

    return 0;
}
