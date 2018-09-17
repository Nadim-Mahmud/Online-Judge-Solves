#include<bits/stdc++.h>

using namespace std;
int ara[1005],dp[1005][2],n;

int rec(int i,int j){

    if(i>n) return 0;
    //cout<<j<<endl;
    if(j==1&&i==n) return 0;
    if(dp[i][j] != -1)  return dp[i][j];

    int c1=0,c2=0;

    c2 += rec(i+1,j);

    if(i==1) j=1;
    //cout<<i<<j<<endl;
    c1 += ara[i] + rec(i+2,j);

    return dp[i][j] = max(c1,c2);
}

int main(){

    int i,l,t,cas=0;
   // freopen("1033.txt","r",stdin);
    cin>>t;
    while(++cas<=t){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        printf("Case %d: %d\n",cas,rec(1,0));
    }
    return 0;
}
