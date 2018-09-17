#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    long long a,n,c,t,i,j;

    cin>>t;
    for(i = 1;i<=t;i++){

        scanf("%lld",&a);

        c = 1;

        if(a%2 != 0) printf("Case %lld: Impossible\n",i);
        else{

            for(j=1;j<=1000;j++){

                c = c*2;
                a = a/2;
                if(a%2 != 0) break;
            }
            printf("Case %lld: %lld %lld\n",i,a,c);
        }
    }
    return 0;
}
