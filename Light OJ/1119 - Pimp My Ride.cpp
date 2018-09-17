#include<bits/stdc++.h>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define MX 1000000000
#define ll long long
#define P(n) cout<<n<<endl
#define P2(x,y) cout<<x<<" "<<y<<endl

using namespace std;

int ara[25][25],dp[(1<<14)+5],n;

int rec(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];

    int pr=0,ttl=0,ans = MX,i,j,tmp;

    for(i=0;i<n;i++){
        if(!(chk(mask,i))){
            pr = ara[i][i];
            for(j=0;j<n;j++){
                if(i!=j&&(chk(mask,j))){
                    pr+=ara[i][j];
                }
            }
            ttl = pr + rec(on(mask,i));
            ans = min(ans,ttl);
        }
    }
    return dp[mask] = ans;
}

int main()
{
    int cas=0,ts,i,j,x=15;
    //freopen("1119.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        printf("Case %d: %d\n",cas,rec(0));
    }
    return 0;
}
