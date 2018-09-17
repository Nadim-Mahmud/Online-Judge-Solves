#include<iostream>
#include<cstdio>
#include<cmath>
#define pi 3.141592653589793238
#define eps 0.0000001

using namespace std;


bool fn(double x,double y){

    if(abs(x-y)<=eps) return true;
    else return false;

}


int main(){

    int t,i;
    double a,b,c,A,x,y,x1,y1,x2,y2,s,n;

   // freopen("1433.txt","r",stdin);

    cin>>t;
    for(i=1;i<=t;i++){

        scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x1,&y1,&x2,&y2);

        a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        b = sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
        c = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));


        if((x==x1&&x1==x2)||(y==y1&&y1==y2)){

            if(fn(a,b)){
                s = pi*a;
             }
             else if(fn(b,c)){
                s = pi * b;
             }
             else if(fn(c,a)){
                s = pi*c;
             }
        }
        else{

            if(abs(a-b)<=eps){
                a = c;
                c = b;
            }
            if(abs(a-c)<=eps){
                a = b;
                b = c;
            }

            A = ((b*b + c*c - a*a)/(2*b*c));
            A = acos(A);
            s = A*b;
        }


        printf("Case %d: %.8lf\n",i,s);

    }

    return 0;
}
