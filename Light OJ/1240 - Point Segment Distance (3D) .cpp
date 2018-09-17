#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
using namespace std;
double x1,yy,z1,x2,y2,z2,x,y,z;

double dist(double a1,double b1,double c1,double a2,double b2,double c2){
    return sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1)+(c2-c1)*(c2-c1));
}

double tns(){
    double l=0,h=1,lp,rp,res1,res2,a,b,c;
    a = x2-x1;
    b = y2-yy;
    c = z2-z1;
    int loo=100;
    while(loo--){
        lp = (l*2+h)/3;
        rp = (h*2+l)/3;
        res1 = dist(x1+lp*a,yy+lp*b,z1+lp*c,x,y,z);
        res2 = dist(x1+rp*a,yy+rp*b,z1+rp*c,x,y,z);
        if(res1>res2) l = lp;
        else h = rp;
    }
    return min(res1,res2);
}

int main()
{
    int i,j,k,n,ts,cas=0;
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&x1,&yy,&z1,&x2,&y2,&z2,&x,&y,&z);
        printf("Case %d: %.7lf\n",cas,tns());
    }
    return 0;
}
