#include<iostream>
#include<cstdio>



using namespace std;

int main(){

    double t,r,pi = 3.141592653589793,x;
    int i;

    cin>>t;

    for(i = 1;i<=t;i++){

        cin>>r;

        x = (4*r*r)-(pi*r*r) + 0.00000001;

        printf("Case %d: %.2lf\n",i,x);

    }

    return 0;
}
