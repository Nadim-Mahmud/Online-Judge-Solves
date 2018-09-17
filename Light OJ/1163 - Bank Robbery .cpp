#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll i,j,k,x,y,a,b,n,m,cn=0,ts,cas=0;
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld",&n);
        printf("Case %lld: ",cas);
        a =  n/9;
        if(n%9==0){
            printf("%lld %lld\n",n+a-1,n+a);
        }
        else{
            printf("%lld\n",n+a);
        }
    }
    return 0;
}



///Pattern finder:::
/*
int fn(int i){
    return (i-i/10);
}
int ara[10000000];
int main(){
    int i,j,k,m,cn=0,a,b;
    freopen("out.txt","w",stdout);
    for(i=10;i<=20000;i++){
        ara[fn(i)]++;
        a = i - fn(i);
        if(a!=b){
            cout<<"----> "<<cn<<endl;
            cn=0;
        }
        //if(fn(i)==fn(i-1)||fn(i)==fn(i+1))
        cout<<i<<" : "<<fn(i)<<endl;
        cout<<a<<endl;
        cn++;
        b = a;
    }
    for(i=1;i<=800;i++){
        //if(ara[i]>1)cout<<i<<" == "<<ara[i]<<endl;
    }
    return 0;
}
*/
