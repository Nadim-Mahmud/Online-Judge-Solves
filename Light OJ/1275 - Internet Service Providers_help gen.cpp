#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll cas=0,t,a,n,c,i,j,ans,x;

    cin>>t;
    while(++cas<=t){

        scanf("%lld %lld",&n,&c);

        for(i=1;i<=(c/n);i++){
            ans = i*(c-i*n);

            if(i==1) a = ans;

            if(ans>=a){
                a = ans;
                x = i;
                //cout<<i<<":"<<ans<<" "<<a<<endl;
            }
            cout<<i<<":"<<ans<<" "<<a<<endl;
        }

        printf("Case %lld: %lld\n",cas,x);
    }
    return 0;
}

