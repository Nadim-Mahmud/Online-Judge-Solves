#include <bits/stdc++.h>
#define ll long long
#define p(X) cout<<"db "<<X<<endl;
#define pp(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
#define MX 100000000;
using namespace std;
///LOJ 1057 - Collecting Gold Backtrak
///Geting WA

int n,m,dp[21][21],gl,stx,sty,mr[21] ;

struct node{
    int x,y;
    node(){};
    node(int a,int b){
        x = a,y = b;
    }
}ara[21];

int dist(node a,node b){
    return max(abs(a.x-b.x),abs(a.y-b.y));
}

int bctk(int n,int pos)
{
    if(gl==n) return dist(ara[pos],ara[20]);
    if(dp[n][pos]>-1) return dp[n][pos];

    int i,ret,tmp;
    ret = MX;
    for(i=0;i<gl;i++){
        if(!mr[i]){
            //p(i)
            mr[i] = 1;
            tmp = dist(ara[i],ara[pos]) + bctk(n+1,i);
            mr[i] = 0;
            ret = min(tmp,ret);
        }
    }
    return dp[n][pos] = ret;
}


int main()
{
    int i,j,a,b,ts,cn=0,cas=0,x,y,ans;
    char ch;
    freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        memset(mr,0,sizeof mr);
        gl = 0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf(" %c",&ch);
                if(ch=='g'){
                    ara[gl++] = node(i,j);
                }
                if(ch=='x'){
                    ara[20] = node(i,j);
                }
            }
        }
        //cout<<gl<<endl;
        printf("Case %d: %d\n",cas,bctk(0,20));
    }
    return 0;
}

