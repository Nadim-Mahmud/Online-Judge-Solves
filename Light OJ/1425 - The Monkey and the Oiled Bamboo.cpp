#include<iostream>
#include<cstdio>
#define ll long long

using namespace std;

ll ara[100005];

int main(){

    ll cas=0,t,i,a,b,c,ans,mx,n;

    cin>>t;
    while(++cas<=t){
        scanf("%lld",&n);
        mx = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&ara[i]);
            if(i != 1){
               if(mx < (ara[i])-ara[i-1]) mx = ara[i] - ara[i-1];
            }
            else mx = ara[i];
        }
        ans = mx;
        for(i=1;i<=n;i++){
            a = ara[i] - ara[i-1];
            if(i==1 && ara[i] == mx) mx--;
            else{
                if(a > mx) ans = mx = ans + 1;
                else if(a == mx) mx--;
            }
            //cout<<mx<<endl;
        }
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
