#include<bits/stdc++.h>

using namespace std;

double hi,mid,lo,x,y,h,f;

int check(double d){
    double h1,h2;
    h1 = sqrt(x*x - d*d);
    h2 = sqrt(y*y - d*d);
    if(abs(h - h1*h2/(h1+h2)) < 10e-14) return 0;
    else if(h < (h1*h2)/(h1+h2)) return 1;
    else return -1;
}

double bisec(){
    int c=100;
    lo = 0;
    while(1){
        mid = (lo+hi)/2.0;
        //cout<<mid<<endl;
        if(check(mid) == -1) hi = mid;
        else if(check(mid) == 1) lo = mid;
        else break;
    }
    return mid;
}

int main(){

    int t,cas=0,i,j,k;
    cin>>t;
    while(++cas<=t){

        scanf("%lf %lf %lf",&x,&y,&h);
        hi = min(x,y);
        //cin>>f;
        //cout<<check(f)<<endl;
        printf("Case %d: %.10lf\n",cas,bisec());
    }
    return 0;
}
