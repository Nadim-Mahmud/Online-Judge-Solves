#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    double v1,v2,v3,a1,a2,t1,t2,s,d;
    int cas=0,n;

    scanf("%d",&n);
    while(++cas<=n){

        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

        d = (v1*v1)/(2*a1) + (v2*v2)/(2*a2);

        t1 = v1/a1;
        t2 = v2/a2;

        if(t1>=t2) s = v3*t1;
        else s = v3*t2;

        printf("Case %d: %.10lf %.10lf\n",cas,d,s);
    }
    return 0;
}
