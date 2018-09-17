#include<iostream>
#include<cstdio>
#include<cmath>
#define pi 2*acos(0.0)

using namespace std;

int main(){

    int i,t;

    double n,R,r,x,y;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%lf %lf",&R,&n);

        x = sin(pi/n);
        r = (R*x)/(1.0 + x);

        printf("Case %d: %.10lf\n",i,r);;
    }
    return 0;
}
