#include<bits/stdc++.h>
#define ll long long
#define eps 10e-6
#define MX 10000009
using namespace std;

int pr[664579+50],in=0;
bool ap[MX];
void siv()
{
    int i,j,sq,p;
    sq=sqrt(MX-2)+2;
    ap[1]=1;
    for(i=3;i<sq;i+=2){
        if(!ap[i]){
            for(j=i*i;j<MX;j+=i+i)ap[j]=1;
        }
    }
    pr[++in] = 2;
    for(i=3;i<MX;i+=2){
        if(!ap[i]){
            pr[++in]=i;
        }
    }
}



int main(){
    ll i,j,k,l,n,m,ts,cas=0,ans,cn;
    //freopen("out.txt","w",stdout);
    siv();
    cin>>ts;
    while(++cas<=ts){
        ans=1;
        scanf("%lld",&n);
        for(i=1;i<=in&&pr[i]*pr[i]<=n;i++){
            cn=0;
            while(n%pr[i]==0){
                cn++;
                n /= pr[i];
                //cout<<cn<<endl;
            }
            ans *= (2*cn+1);
        }
        if(n>1) ans *= 3;
        printf("Case %lld: %lld\n",cas,ans/2+1);
    }
    return 0;
}
