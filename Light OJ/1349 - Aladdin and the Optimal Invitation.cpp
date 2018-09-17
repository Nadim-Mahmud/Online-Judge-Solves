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
#define MX 50005
using namespace std;
int ax[MX],ay[MX];
int main()
{
    int i,j,a,b,ts,cn=0,cas=0,n,m,q,sum,tmp,mxx,mxy,x,y;
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        scanf("%d %d %d",&n,&m,&q);
        sum=0;
        MS(ax,0)
        MS(ay,0)
        for(i=1;i<=q;i++){
            scanf("%d %d %d",&x,&y,&a);
            ax[x] += a;
            ay[y] += a;
            sum += a;
        }
        tmp=0,x=1,y=1;
        a = (sum+1)/2;
        for(i=1;i<=n;i++){
            tmp += ax[i];
            x = i;
            if(tmp>=a) break;
        }
        tmp=0;
        for(i=1;i<=m;i++){
            tmp += ay[i];
            y = i;
            if(tmp>=a) break;
        }
        printf("Case %d: %d %d\n",cas,x,y);
    }
    return 0;
}
