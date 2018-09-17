#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){

    int t,i;
    double x,r1,r2,r3,a,b,c,s,area,A1,A2,A3,ar,pi;

    //freopen("1331.txt","r",stdin);

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%lf %lf %lf",&r1,&r2,&r3);

        a = r1 + r2;
        b = r1 + r3;
        c = r2 + r3;

        s = (a + b + c)/2.0;

        area = sqrt(s*(s-a)*(s-b)*(s-c));

        A1 = acos((b*b + c*c - a*a)/(2.0*b*c));
        A2 = acos((a*a + c*c - b*b)/(2.0*a*c));
        A3 = acos((a*a + b*b - c*c)/(2.0*a*b));

        ar = (A1*r3*r3 + A2*r2*r2 + A3*r1*r1)*.5;

        area = area - ar;

        if(r1 == 0 && r2 == 0 && r2 == 0) area = 0;

        printf("Case %d: %.10lf\n",i,area);

    }


    return 0;
}
