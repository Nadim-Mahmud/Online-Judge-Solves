#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){

    int t,i;
    double r1,r2,h,p,r,v,pi;

    cin>>t;
    pi = 2*acos(0.0);

    for(i=1;i<=t;i++){

        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);

        r = r2 + (p/h)*(r1 - r2);

        v = (1/3.0)*pi*p*(r*r + r*r2 + r2*r2);

        printf("Case %d: %.9lf\n",i,v);
    }
    return 0;
}
