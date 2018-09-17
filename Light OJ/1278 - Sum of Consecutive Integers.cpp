
#include<bits/stdc++.h>
#define MX 10000000
#define MXP 664579
#define usi unsigned int
#define ll long long
#define chk(X) (ara[X>>5]&(1<<((X&31)>>1)))
#define mark(X) (ara[X>>5]|=(1<<((X&31)>>1)))
using namespace std;

int ara[(MX/32)+2],c=0,pr[MXP+5],v=0;

void sieve(){
    int i,j,r,n=MX;
    r = sqrt(n)+1;
    pr[++v] = 2;
    for(i=3; i<=r;i+=2){
        if(!chk(i)){
            pr[++v] = i;
            for(j=i*i;j<=n;j+=(i<<1)){
                mark(j);
            }
        }
    }
    for(i=r+2;i<=n;i+=2){
        if(!chk(i)){
            pr[++v] = i;
        }
    }
}

int main(){

    ll t,cas=0,i,j,n,c,c1,divs;
    sieve();
    //freopen("love.txt","r",stdin);
    //cout<<v<<endl;
    cin>>t;
    //n=100000000000000;
    while(++cas<=t){
        scanf("%lld",&n);
        //n--;
        divs = 1;
        for(i=1;i<=v&&pr[i]*pr[i]<=n;i++){
            c=0;
            while(n%pr[i]==0){
                n /= pr[i];
                c++;
            }
            if(c!=0&&pr[i]!=2) divs *= (c+1);
        }
        if(n>1&&n!=2) divs *= 2;
        printf("Case %lld: %lld\n",cas,divs-1);
    }
    return 0;
}
