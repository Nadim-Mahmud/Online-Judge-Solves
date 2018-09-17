#include<bits/stdc++.h>
#define ll long long
#define MX 10000000
using namespace std;

bool mark[10000000+5];
int pr[664579+5],v=0;

void sieve(void){
    int i,j,s = sqrt(MX)+1;
    pr[++v] = 2;
    for(i=3;i<=MX;i+=2){
        if(!mark[i]){
            pr[++v] = i;
            if(i<=s){
                for(j=i*i;j<=MX;j+=(i<<1)){
                    mark[j] = 1;
                }
            }
        }
    }

}

int main(){

    ll i,j,n,c,ans,x;
    sieve();
    //freopen("11466.txt","r",stdin);
    //cout<<v<<endl;
    while(1){
        scanf("%lld",&x);
        if(x==0) break;
        c=0,ans=0;
        n = abs(x);
        //0cout<<pr[1]<<endl;
        for(i=1;i<=v&&pr[i]*pr[i]<=n;i++){
           // cout<<pr[i]<<endl;
           if(n%pr[i]==0)c++;
            while(n%pr[i]==0){
                n/=pr[i];
                ans=pr[i];
            }
        }
        if(n>1) ans=n,c++;;
        //cout<<n<<ans;
        if(c>1&&ans!=0 && ans!=x) printf("%lld\n",ans);
        else printf("-1\n");
    }

    return 0;
}
