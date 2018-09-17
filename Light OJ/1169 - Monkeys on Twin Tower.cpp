#include<bits/stdc++.h>
using namespace std;

int a1[1005],a2[1005],b1[1005],b2[1005],n,dp[1005][5];

int calc(int i,int mr)
{
    if(i>n) return 0;

    if(dp[i][mr]!=-1) return dp[i][mr];

    int s1=0,s2=0;

    if(mr==0){
        s1 = a1[i] + calc(i+1,0);
        s2 = a1[i] + b1[i] + calc(i+1,1);
    }
    else{
        s1 = a2[i] + calc(i+1,1);
        s2 = a2[i] + b2[i] + calc(i+1,0);
    }
    return dp[i][mr] = min(s1,s2);
}


int main()
{
    int i,j,k,ts,cas=0;
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a1[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&a2[i]);
        }
        for(i=1;i<n;i++){
            scanf("%d",&b1[i]);
        }
        for(i=1;i<n;i++){
            scanf("%d",&b2[i]);
        }
        printf("Case %d: %d\n",cas,min(calc(0,0),calc(0,1)));
    }
    return 0;
}
