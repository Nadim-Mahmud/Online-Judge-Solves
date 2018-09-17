#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    unsigned long long t,i,n,c,j,m;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%llu",&n);
        c = 0;
        m = n;
        for(;m != 0;){

        if(m%2 == 1) c++;
        m = m/2;

        }

        if(c%2 == 0) printf("Case %llu: even\n",i);
        else printf("Case %llu: odd\n",i);

    }

    return 0;
}
