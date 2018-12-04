#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll cn=0,ts,cas=0,n,m;
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld",&n);
        cn=0;
        m = 5;
        while(m<=n){
            cn += n/m;
            m *= 5;
        }
        printf("%lld\n",cn);
    }
    return 0;
}
