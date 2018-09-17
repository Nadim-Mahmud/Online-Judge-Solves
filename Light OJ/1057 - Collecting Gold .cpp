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

int n,m,dp[21][1<<15],gl,stx,sty;

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

int solve(int n,int bit){
    if(bit==((1<<gl)-1)) return dist(ara[20],ara[n]);
    if(dp[n][bit]!=-1) return dp[n][bit];
    int i,r,bb,ret = MX;
    for(i=0;i<gl;i++){
        if(!chk(bit,i)){
            bb = on(bit,i);
            r = dist(ara[n],ara[i]) + solve(i,bb);
            ret = min(ret,r);
        }
    }
    return dp[n][bit] = ret;
}

int main()
{
    int i,j,a,b,ts,cn=0,cas=0,x,y,ans;
    char ch;
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
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
        ans = solve(20,0);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}

