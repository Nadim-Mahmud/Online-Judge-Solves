#include<bits/stdc++.h>
#define MX 100000
#define ll long long
using namespace std;

int pr[MX+5],v = 0;

void sieve(void){

    int i,j,r;
    r = sqrt(MX);
    pr[++v] = 2;
    for(i=3;i<=MX;i+=2){
        if(!pr[i]){
            pr[++v] = i;
            if(i<=r){
                for(j=i*i;j<=MX;j+=i<<1){
                    pr[j] = 1;
                }
            }
        }
    }
}

int main(){

    ll cas=0,t,i,n,c,c1,mini,x;
    sieve();
    cin>>t;
    while(++cas <= t){
        scanf("%lld",&n);
        c = 0,mini=1000000000,x = 0;
        if(n<0) x = 1,n = -1*n;
        for(i=1; i <= v && pr[i]*pr[i] <= n; i++){
            c = 0;
            while(n%pr[i] == 0){
                n /= pr[i];
                c++;
            }
            if(mini>c&&c!=0) mini = c;
        }
        if(n>1) mini = 1;
        if(mini>1 && mini%2==0 && x==1){
            while(mini%2==0){
                mini /= 2;
            }
        }
        printf("Case %lld: %lld\n",cas,mini);
    }
    return 0;
}
