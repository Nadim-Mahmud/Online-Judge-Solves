#include<cstdio>
#include<cmath>

int main(){

    int t, cas=0;
    double a, b,r,theta,s,x;
    scanf("%d",&t);
    while(++cas<=t){
        scanf("%lf : %lf", &a, &b);
        r = sqrt(b*b + a*a)/2.0;
        s = r*acos((2.0*r*r - b*b)/(2.0 * r * r));
        x = 400.0/(2.0*a + 2.0*s);
        printf("Case %d: %.10lf %.10lf\n", cas, x*a, x*b);
    }
    return 0;
}
