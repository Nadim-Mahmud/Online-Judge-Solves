#include<bits/stdc++.h>

using namespace std;

int main(){

    int t,cas=0;
    double w,l,x,m;

    cin>>t;
    while(++cas<=t){

        scanf("%lf %lf",&l,&w);

        m = (l+w);
        x = (m - sqrt(m*m - 3.0*w*l))/6.0;

        printf("Case %d: %.9lf\n",cas,(w - 2.0*x)*(l - 2.0*x)*x);
    }
    return 0;
}
