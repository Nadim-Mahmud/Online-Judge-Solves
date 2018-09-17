#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 10e-10
#define dd double

using namespace std;

dd a1,b1;

int check(dd x){
    dd r,s,m,a,b;
    a = a1*x;
    b = b1*x;
    r = (sqrt(a*a + b*b))/2.0 + eps;
    s = r*acos((2.0*r*r - b*b)/(2.0*r*r));
    m = 2*s + 2*a + eps;
    //cout<<"m:"<<m<<endl;
    if(abs(m-400)<=10e-18) return 0;
    else if(m > 400) return 1;
    else if(m < 400) return -1;
}

dd bisec(){
    int i,c=1000;
    dd l = 0,h=500,mid;
    while(abs(h-l)>10e-10){
        mid = (h+l)/2.0;
        //cout<<mid<<"   "<<check(mid)<<endl;
        if(check(mid) == 1) h = mid;
        else if(check(mid) == -1) l = mid;
        else break;
    }
    return mid;
}
int main(){

    int cas=0,t;
    char ch;
    dd x;
    cin>>t;
    while(++cas<=t){
        scanf("%lf %c %lf",&a1,&ch,&b1);
        x = bisec();
       // cout<<x<<endl;
        printf("Case %d: %.10lf %.10lf\n",cas,x*a1,x*b1);
    }
    return 0;
}
