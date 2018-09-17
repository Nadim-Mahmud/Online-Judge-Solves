#include<bits/stdc++.h>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n&(~(1<<i))
#define MX 1<<30
#define ll long long
#define P(n) cout<<n<<endl;
#define P2(x,y) cout<<x<<" "<<y<<endl;
using namespace std;
int ara[20],dp[(1<<15)+5],n;
char str[20][20];

int rec(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];

    int i,j,st=1,tmp=1,ans=MX;

    for(i=0;i<n;i++){
        if(!(chk(mask,i))){
            st = 1,tmp = 1;
            for(j=0;j<n;j++){
                if(i!=j&&chk(mask,j)) tmp = (int)(str[j][i] - '0');
                st = max(st,tmp);
            }
            tmp = ceil((double)ara[i]/(double)st) + rec(on(mask,i));
            ans = min(ans,tmp);
        }
    }
    return dp[mask] = ans;
}

int main()
{
    int i,j,cas=0,ts,k;
    //freopen("1037.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&ara[i]);
        }
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
        }
        printf("Case %d: %d\n",cas,rec(0));
    }
    return 0;
}
