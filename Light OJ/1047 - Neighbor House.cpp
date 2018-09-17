#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000
using namespace std;

int ara[23][5],n;
ll dp[23][5];

ll cost(int  i,int j)
{
    if(i >= 0 && i < n && j >= 0 && j < 3){
        //cout<<i<<" "<<j<<endl;
        if(dp[i][j] != -1) return dp[i][j];

        ll ret = inf;

        ret = min(ret , ara[i][j] + cost(i+1,j+1));
        //cout<<i<<" "<<j<<" "<<ret<<endl;
        ret = min(ret , ara[i][j] + cost(i+1,j-1));
        ret = min(ret , ara[i][j] + cost(i+1,j+2));
        ret = min(ret , ara[i][j] + cost(i+1,j-2));

        return dp[i][j] = ret;
    }
    else if(j<0||j>=3) return inf;
    else return 0;
}


int main()
{
    ll cas=0,t,i,j,ans;
    //freopen("1047.txt","r",stdin);
    cin>>t;
    while(++cas<=t){

        scanf("%lld",&n);
        memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++){
            for(j=0;j<3;j++){
                scanf("%d",&ara[i][j]);
            }
        }

        ans = min(cost(0,0),cost(0,1));
        ans = min(ans,cost(0,2));

        printf("Case %lld: %lld\n",cas,ans);
    }

    return 0;
}
