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

int ara[10000];

int main()
{
    int i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum,in=1;
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>ara[i];
    }
    for(i=1;i<=m;i++){
        cin>>a;
        while(ara[in]>a) in++;
        if(ara[in]<=a&&in<=n) cn++,in++;
    }
    cout<<cn<<endl;
    return 0;
}

