#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    long long i,cas=0,t,n,a,b,c;

    scanf("%lld",&t);
    while(++cas <= t){

        c = 1;
        scanf("%lld %lld",&n,&b);
        a = b;
        while(a){
            if(a>=n){
                a = a%n;
                if(a == 0) break;
                //cout<<a<<endl;
            }
            else{
                a = a*10 + b;
                c++;
            }
        }
        printf("Case %lld: %lld\n",cas,c);
    }
    return 0;
}
