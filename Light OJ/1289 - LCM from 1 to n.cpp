#include<bits/stdc++.h>
#define MX 100000000
#define MXP 5761455
#define usi unsigned int
#define ll long long
#define chk(X) (ara[X>>5]&(1<<((X&31)>>1)))
#define mark(X) (ara[X>>5]|=(1<<((X&31)>>1)))
using namespace std;

int ara[(MX/32)+2],c=0,pr[MXP+5],v=0;
usi mul[MXP+5];

void sieve(){
    int i,j,r,n=MX;
    r = sqrt(n)+1;
    pr[++v] = 2;
    mul[v] = 2,mul[0] = 1;
    for(i=3; i<=r;i+=2){
        if(!chk(i)){
            pr[++v] = i;
            mul[v] = mul[v-1]*i;
            for(j=i*i;j<=n;j+=(i<<1)){
                mark(j);
            }
        }
    }
    for(i=r;i<=n;i+=2){
        if(!chk(i)){
            pr[++v] = i;
            mul[v] = mul[v-1]*i;
        }
    }
}

int bins(int n,int l){
    int h = MXP,m;
    while(h-l>4){
        m = (l+h)/2;
        if(pr[m]<n) l = m;
        else if(pr[m]>n) h = m;
        else break;
    }
    for(l;l<=h;l++){
        if(pr[l+1]>n) break;
    }
    return l;
}

int main(){

    int i,j,cas=0,t,x,n,k,c;
    usi lcm;
    sieve();
    pr[MXP+1] = 1000000000;
    cin>>t;
    while(++cas<=t){
        scanf("%d",&n);
        lcm = 1;
        int c1=0;
        for(i=1;pr[i]*pr[i]<=n;i++){
            x = n;
            c = 0;
            while(x>=pr[i]){
                if(c==1) lcm = lcm * pr[i];
                x /= pr[i];
                c=1;
            }
        }
        lcm *= mul[bins(n,i-1)];
        printf("Case %d: %u\n",cas,lcm);
    }
    return 0;
}
