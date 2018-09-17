#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll i,cas=0,ts,x,y,a,b,ans;
    cin>>ts;
    while(ts--){
        scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
        printf("Case %lld: %lld\n",++cas,__gcd(abs(x-a),abs(y-b))+1);
    }
    return 0;
}
