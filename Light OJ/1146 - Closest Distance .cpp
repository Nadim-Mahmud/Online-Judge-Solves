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
double ax,ay,bx,by,cx,cy,dx,dy;

double dist(double x1,double y1,double x2,double y2 ){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double tns(){
    double l=0,h=1,lp,rp,r1,r2,a,b,c,d;
    int lo=100;
    a = bx - ax;
    b = by - ay;
    c = dx - cx;
    d = dy - cy;
    while(lo--){
        lp = l + (h-l)/3;
        rp = lp + (h-l)/3;
        r1 = dist(ax+a*lp,ay+b*lp,cx+c*lp,cy+d*lp);
        r2 = dist(ax+a*rp,ay+b*rp,cx+rp*c,cy+rp*d);
        //cout<<r1<<" "<<r2<<endl;
        if(r1>=r2) l = lp;
        else h = rp;
    }
    return min(r1,r2);
}


int main()
{
    int i,j,k,n,ts,cas=0;
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
        printf("Case %d: %.8lf\n",cas,tns());
    }
    return 0;
}

