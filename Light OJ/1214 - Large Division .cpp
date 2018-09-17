#include<iostream>
#include<cstdio>
#include<cmath>

char s[10000000];

using namespace std;

int main(){

    long long t,a,x,n,i,j;

    cin>>t;

    for(j=1;j<=t;j++){

        scanf("%s",s);
        scanf("%lld",&n);

        n = abs(n);
        a = 0;

        for(i=0;s[i] != '\0';i++){

           // cout<<"a1: "<<a<<endl;

            if(i==0 && s[0] == '-') continue;
            else{

                a = a*10 + (int) s[i] - '0';
            }

            if(a >= n){

                x = a/n;
                a = a - x*n;
            }
        }

        if(a == 0) printf("Case %lld: divisible\n",j);
        else printf("Case %lld: not divisible\n",j);
    }

    return 0;
}
