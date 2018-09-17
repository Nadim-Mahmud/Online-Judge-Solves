#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    long long t,n,a,b,c,x,y,z,i;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%lld %lld %lld",&a,&b,&c);

        x = (a*a + b*b) - c*c;
        y = (b*b + c*c) - a*a;
        z = (a*a + c*c) - b*b;

        if(a == 0 || b == 0 || c == 0) printf("Case %lld: no\n",i);
        else if(x == 0 || y == 0 || z == 0) printf("Case %lld: yes\n",i);
        else printf("Case %lld: no\n",i);

    }

    return 0;
}
