#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 10e-9

using namespace std;

double area(double a,double b,double c){

    double ar,s;
    s = (a + b + c)/2.0;
    ar = sqrt(s*(s-a)*(s-b)*(s-c)) + eps;
    return ar;
}


int main(){

    int cas=0,t,i;
    double a,b,c,x,y,z,ar1,ar2,r,r1,l,h,m,ac,ab,ar;
    cin>>t;
   while(++cas<=t){

        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);

        ar1 = area(a,b,c);

        l = 0;
        h = a;
        ac = c/a ;
        ab = b/a ;

        while(1){
            m = (l+h)/2.0;
            z = m*ab;
            y = m*ac;
            ar2 = area(m,y,z);
            ar = ar1 - ar2;
            r1 = ar2/ar +eps;
           // cout<<"r:"<<r1<<"r2:"<<r<<endl;

            //cout<<l<<" "<<m<<" "<<h<<endl;
            if(r1>r) h = m;
            else if( r1<r) l = m;

            if(abs(r1-r)<=10e-12) break;
        }
    printf("Case %d: %.10lf\n",cas,m);
    }
    return 0;
}

