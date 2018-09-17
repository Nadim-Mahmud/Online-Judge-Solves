#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MD 1000000007
using namespace std;

ll ft[3000100];
void fact(){
    ft[0]=1;
    for(int i=1;i<=3000050;i++){
        ft[i] = ft[i-1]*i % MD;
    }
}

pii extnuc(ll a,ll b){
    if(b==0)return pii(1,0);
    pii d=extnuc(b,a%b);
    return pii(d.second,d.first-d.second*(a/b));
}

ll modi(ll n){
    pii d=extnuc(n,MD);
    return ((d.first%MD)+MD)%MD;
}


int main(){
    ll i,j,k,n,m,ts,cas=0,a,b,ans;
    fact();
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&n,&k);
        a = ft[n+k-1];
        b = ft[k-1]*ft[n]%MD;
        ans = (a*modi(b%MD))%MD;
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
