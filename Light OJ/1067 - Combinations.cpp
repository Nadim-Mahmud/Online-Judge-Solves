#include<bits/stdc++.h>
#define MX 1000000
#define MD 1000003
#define ll long long
#define pii pair<int,int>

using namespace std;

ll ara[1000005];

void fact(void){
    int i;
    ara[0] = 1;
    for(i=1;i<=MX;i++){
        ara[i] = (ara[i-1] * i) % MD;
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
    pii d=extnuc(n,MD);
    return ((d.first%MD)+MD)%MD;
}


int main(){

    ll cas=0,t,i,j,n,r,x,up,lw,cmb;
    fact();
    cin>>t;
    while(++cas<=t){

        scanf("%lld %lld",&n,&r);

        lw = (ara[r] * ara[n-r]) % MD;
        cmb = (ara[n] * modi(lw)) % MD;

        printf("Case %lld: %lld\n",cas,cmb);
    }
    return 0;
}
