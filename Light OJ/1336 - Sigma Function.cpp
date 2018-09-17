#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int cas=0,t;
    ll n,m,sum,i,j,x,cnt=0,r;
    scanf("%d",&t);
    //n=1000000000000;
    while(++cas<=t){
        scanf("%lld",&n);
        //n--;
        cnt = 0;
        for(i=1;i*i<=n;i+=2){
            x = i*i;
            while(x<=n){
                x = x<<1;
                cnt++;
            }
        }
        printf("Case %d: %lld\n",cas,(n-cnt));
    }
    return 0;
}


