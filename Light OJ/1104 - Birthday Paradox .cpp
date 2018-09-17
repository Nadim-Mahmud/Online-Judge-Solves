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

int main()
{
    int i,j,ts,cn=0,cas=0,n,m,x,y,sum;
    double a,b;
    scanf("%d",&ts);
    while(++cas<=ts){
        scanf("%d",&n);
        a = 1;
        for(i=1;;i++){
            a *= (double)(n-i)/(double)n;
            if(a<=.5) break;
        }
        printf("Case %d: %d\n",cas,i);
    }
    return 0;
}
