#include<bits/stdc++.h>
using namespace std;

int ur[510][510],rd[510][510],dp[510][510],n,m;

int ref(int i ,int j){
    if(i<1||j<1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = max(ref(i-1,j)+ur[i][j],ref(i,j-1)+rd[i][j]);
}

int main(){
    int i,j,k,ts,cas=0,x,y;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        memset(dp,-1,sizeof dp);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&x);
                ur[i][j] = ur[i][j-1] + x;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&x);
                rd[i][j] = rd[i-1][j] + x;
            }
        }
        printf("Case %d: %d\n",cas,ref(n,m));
    }
    return 0;
}
