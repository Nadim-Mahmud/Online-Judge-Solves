#include<bits/stdc++.h>
#define ll long long
#define MX 1000050
using namespace std;

bool mr[MX];
int pr[100000],in=0;

void siv(){
    int i,j,sq = sqrt(MX) + 1;
    for(i=4;i<MX;i+=2) mr[i] = 1;
    for(i=3;i<=sq;i++){
        if(!mr[i]){
            for(j=i*i;j<MX;j+=i<<1){
                mr[j] = 1;
            }
        }
    }
    pr[++in] = 2;
    for(i=3;i<MX;i+=2){
        if(!mr[i]) pr[++in] = i;
    }
}

int main(){
    ll i,j,a,b,k,ts,cas=0,cn,ans,sq,tmp;
    siv();
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&a,&b);
        if(b*b>=a){
            ans  = 0;
            goto L1;
        }
        ans = 1;
        tmp = a;
        for(i=1;pr[i]*pr[i]<=a&&i<in;i++){
            cn = 1;
            while(a%pr[i]==0){
                cn++;
                a /= pr[i];
            }
            ans *= cn;
        }
        if(a>1) ans *= 2;
        ans >>= 1;
        for(i=1;i<b;i++){
            if(tmp%i==0) ans--;
        }
        L1: printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
