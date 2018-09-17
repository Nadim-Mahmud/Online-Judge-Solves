#include<bits/stdc++.h>
#define ll long long
#define MX 40000
using namespace std;

ll h,h1,ara[35],n,cnt,w,A[MX],B[MX],s,av=0,bv=0;

void rec(ll ps,ll waight)
{
    if(ps>=h){
        //cout<<waight<<endl;
        if(s==0) A[++av] = waight;
        else B[++bv] = waight;
        return;
    }
    rec(ps+1,waight+ara[ps]);
    rec(ps+1,waight);
}

ll bns(ll tmp){
    ll lw=1,hi=av,md;
    //cout<<tmp<<endl;
    while((hi-lw)>5){
        md = (lw+hi)/2;
        if(A[md]>tmp) hi = md;
        else lw = md;
        //cout<<lw<<" "<<hi<<endl;
    }
    for(lw;lw<=hi;lw++){
        if(A[lw]>tmp) break;
    }
    lw--;
    return lw;
}

int main()
{
    ll i,j,k,a,b,ts=0,cas=0,ans;
    //cout<<pow(2,18)<<endl;
    //freopen("1127.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        av=0,bv=0,ans=0;
        scanf("%lld %lld",&n,&w);
        for(i=0;i<n;i++){
            scanf("%lld",&ara[i]);
        }
        s=0;
        h = ceil((double)n/2.0);
        rec(0,0);
        s=1,h1 = h,h = n;
        rec(h1,0);
        sort(A+1,A+av+1);
//        for(i=1;i<=av;i++) cout<<A[i]<<endl;
//        cout<<"\n\n";
        for(i=1;i<=bv;i++){
            ans += bns(w-B[i]);
            //cout<<ans<<" "<<B[i]<<endl;
        }
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
