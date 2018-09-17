#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 10e-9

using namespace std;

int main(){

    int cas =0,t,i;
    double n,a,b,c,d,s,x,ar,h;

    cin>>t;
    while(++cas<=t){

        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        n = a - c;
        s = (n + b + d)/2.0;
        h = sqrt(s*(s-n)*(s-b)*(s-d)) + eps;
        h = (h*2.0)/n ;
        ar = abs(.5*(a+c)*h) ;

        printf("Case %d: %.10lf\n",cas,ar);
    }
    return 0;
}
