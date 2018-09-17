#include<iostream>
#include<cstdio>

using namespace std;


int main(){

    long long a,t,i,n,m,x;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%lld %lld",&m,&n);

        if(m > n){
            a = m;
            m = n;
            n = a;
        }

        x = 0;

        if(m == 2){
            if(n > 2) x = (n/2+1)/2;
            else x = 1;

            if(n == 1) x = 2;
            else if(n%2 != 0 && (n-1)%4 == 0)  x = (x*m+1)*2;
            else  x = x*m*2;
        }
        else{
            if(n%2 == 0) x = (n/2)*m;
            else{
                if(m%2==0) x = (n/2)*(m/2) + (n/2+1)*(m/2);
                else x = (n/2)*(m/2) + (n/2+1)*(m/2+1);
            }
        }
        if(m == 1) x = n;
        printf("Case %lld: %lld\n",i,x);
    }

    return 0;
}
