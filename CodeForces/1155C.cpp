#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll i,j,k,l,x,y,m,mr=0,n,a,b,mx,mn,gcd=1,ans=-1;

    cin>>n>>m;

    for(i=1;i<=n;i++){
        scanf("%lld",&x);
        if(i!=1){
            if(!mr){
                mr = 1;
                gcd = mn = x-y;
            }
            mn = min(mn,x-y);
            gcd = __gcd(gcd,x-y);
        }
        else k = x;
        y = x;
    }
    for(i=1;i<=m;i++){
        scanf("%lld",&x);
        if(gcd%x==0&&x<=mn){
             ans = i;
        }
    }
    if(ans!=-1){n
        puts("YES");
        cout<<k<<" "<<ans<<endl;
    }
    else{
        puts("NO");
    }
    return 0;
}
