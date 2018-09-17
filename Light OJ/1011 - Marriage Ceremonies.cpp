#include<bits/stdc++.h>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
using namespace std;

int n,ara[20][20],dp[20][(1<<16)+5];

int rec(int pos,int mask)
{
    if(pos>=n||mask==(1<<n)-1) return 0;
    if(dp[pos][mask]!=-1) return dp[pos][mask];

    int st=0,ans=0,j;

    for(j=0;j<n;j++){
        if(!(chk(mask,j))) st = ara[pos][j] + rec(pos+1,on(mask,j));
        ans = max(ans,st);
    }
    return dp[pos][mask] = ans;
}


int main()
{
    int i,j,k,cas=0,ts;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        printf("Case %d: %d\n",cas,rec(0,0));
    }
    return 0;
}
