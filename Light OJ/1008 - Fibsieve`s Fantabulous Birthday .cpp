#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 0.00000001;

using namespace std;

int main(){

    long long t,n,x,y,z,a,i,j=1;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%lld",&n);
        x = sqrt(n) + eps;
        a = x*x;

        if(a == n){
            if(a%2 == 0) printf("Case %lld: %lld %lld\n",i,x,j);
            else printf("Case %lld: %lld %lld\n",i,j,x);
        }
        else{
            x++;
            a = x*x;
            if(a%2 == 0){

                y = a -n;
                z = a - 2*(x-1);

                if(y < x) printf("Case %lld: %lld %lld\n",i,x,y+1);
                else printf("Case %lld: %lld %lld\n",i,(n-z+1),x);
            }
            else{

                y = a - n;
                z = a - (x + (x-2));

                if(y<x) printf("Case %lld: %lld %lld\n",i,y+1,x);
                else printf("Case %lld: %lld %lld\n",i,x,((n-z)+1));
            }
        }
    }
    return 0;
}
