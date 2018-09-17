#include<bits/stdc++.h>
using namespace std;
int ara[105],n,w,k,dp[105][105];

int cnt(int i,int mv)
{
    if(i>n||mv>k) return 0;
    if(dp[i][mv]!=-1) return dp[i][mv];
    int r1=0,r2=0,j;
    for(j=i;j<=n&&(ara[j]<=(ara[i]+w));j++){
        r1++;
        //cout<<i<<" "<<r1<<" "<<ara[j]<<endl;
    }
    if(mv+1<=k) r1 += cnt(j,mv+1);
    r2 = cnt(i+1,mv);
    //cout<<r1<<" "<<r2<<endl;
    return dp[i][mv] = max(r1,r2);
}

int main()
{
    int i,j,ts,cas=0,x;
    //freopen("1017.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%d %d %d",&n,&w,&k);
        for(i=1;i<=n;i++){
            scanf("%*d %d",&ara[i]);
        }
        sort(ara+1,ara+n+1);
        printf("Case %d: %d\n",cas,cnt(1,1));
    }
    return 0;
}
