#include<bits/stdc++.h>
using namespace std;
double s,l,n,c;
double calc(double b){
    double c = l*0.5,th,r;
    r = (c*c/(2.0*b)) + b/2.0;
    th = 2.0*asin(c/r);
    return r*th;
}

double bisec(double hi){
    double mi,lo=0.0;
    for(int i=0;i<=150;i++){
        mi = (lo+hi)/2.0;
        if(calc(mi)>s) hi = mi;
        else lo = mi;
    }
    return mi;
}

int main(){
    int i,j,cas=0,ts,hi;
    //freopen("1137.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%lf %lf %lf",&l,&n,&c);
        s = (1.0+(n*c))*l;
        printf("Case %d: %lf\n",cas,bisec(l));
    }
    return 0;
}
