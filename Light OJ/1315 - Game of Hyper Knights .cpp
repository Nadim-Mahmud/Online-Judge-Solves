#include<bits/stdc++.h>
using namespace std;

int dp[510][510];
int dx[] = {1,-1,-1,-2,-2,-3};
int dy[] = {-2,-2,-3,1,-1,-1};

int rec(int x,int y)
{
    if(x<0||y<0) return -11;
    if(dp[x][y]!=-1) return dp[x][y];

    int i,j,cn=0,a,b;
    set<int>s;
    for(i=0;i<6;i++){
        a = x + dx[i];
        b = y + dy[i];
        s.insert(rec(a,b));
    }
    while(s.find(cn)!=s.end()) cn++;
    return dp[x][y] = cn;
}

int main(){
    int i,j,k,n,m,ts,cas=0,ans=0,x,y;
    memset(dp,-1,sizeof dp);
    cin>>ts;
    while(++cas<=ts){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            ans ^= rec(x,y);
        }
        if(ans) printf("Case %d: Alice\n",cas);
        else printf("Case %d: Bob\n",cas);
    }
    return 0;
}
