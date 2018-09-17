//uva 11827

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll ara[100005];

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){

    ll x,y,i,j,n,c,mx=0,t,cas=0,v,a,b;
    char str[1000005];

    //freopen("11827.txt","r",stdin);

    cin>>t;
    getchar();

    while(++cas <= t){

        x = 0,v=0,c=0;
        gets(str);

        for(i=0;str[i] != '\0' ;i++){

            if(str[i] != ' '){
                if(c==0){
                    c++;
                    x = str[i] - '0';
                }
                else{
                    c++;
                    y = str[i] - '0';
                    x = (x*10 + y);
                }
            }
            else if(str[i+1] != ' ') ara[++v] = x,c = 0;
        }
        if(c != 0) ara[++v] = x;

        //for(i=1;i<=v;i++) cout<<ara[i]<<" ";
       // cout<<endl;
        mx = 0 ;

        for(i=1;i<v;i++){
            for(j=i+1;j<=v;j++){

                x = gcd(ara[i],ara[j]);
                //cout<<ara[i]<<ara[j] <<x <<endl;
                if(mx<x) mx = x;
            }
        }
        printf("%lld\n",mx);
    }
    return 0;
}
