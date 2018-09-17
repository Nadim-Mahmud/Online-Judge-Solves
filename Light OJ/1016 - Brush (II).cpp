#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long

using namespace std;

ll ara[50009];

int main(){

    ll cas=0,t,i,j,x,y,a,b,c;
    cin>>t;
    while(++cas<=t){
        c = 1;
        scanf("%lld %lld",&a,&b);
        for(i=1;i<=a;i++){
            scanf("%lld %lld",&x,&ara[i]);
        }
        sort(ara+1,ara+a+1);
        x = ara[1];
        for(i=1;i<=a;i++){
            if(ara[i]>x+b){
                c++;
                x = ara[i];
            }
        }
        printf("Case %lld: %lld\n",cas,c);

    }
    return 0;
}
