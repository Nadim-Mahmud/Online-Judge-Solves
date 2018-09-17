#include<bits/stdc++.h>

using namespace std;

int ara[105][105],dp[105][105],r,c;

int roc(int i,int j)
{

    if(ara[i][j] <= ara[i][j-1] && ara[i][j] <= ara[i][j+1] && ara[i][j] <= ara[i+1][j] && ara[i][j] <= ara[i-1][j]){
        return 1;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ret1=0,ret2=0,ret3=0,ret4=0,ret;

    if(ara[i][j-1]<ara[i][j]) ret1 += 1 + roc(i,j-1);
    if(ara[i][j+1]<ara[i][j]) ret2 += 1 + roc(i,j+1);
    //cout<<i<<" "<<j<<" "<<ret2<<endl;
    if(ara[i-1][j]<ara[i][j]) ret3 += 1 + roc(i-1,j);
    //cout<<ret3<<endl;
    if(ara[i+1][j]<ara[i][j]) ret4 += 1 + roc(i+1,j);

    ret = max(ret1,ret2);
    ret = max(ret,ret3);
    //cout<<ret<<endl;
    return dp[i][j] = max(ret,ret4);
}

void fill(){
    int i,j;
    for(i=0;i<=104;i++)
        for(j=0;j<105;j++){
            ara[i][j] = 10000;
            dp[i][j] = -1;
        }
}

int main(){

    int i,j,cas = 0,t,ans;
    char str[1000];
    //fill();
    //freopen("10285.txt","r",stdin);
    cin>>t;
    while(++cas <= t)
    {
        scanf("%s %d %d",str,&r,&c);
        //r=3,c=3;
        ans = 0;
        //memset(dp,-1,sizeof dp);
        fill();
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        //cout<<roc(3,1)<<"cc"<<endl;
        //cout<<ara[3][1]<<endl;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                ans = max(ans,roc(i,j));
            }
        }
        printf("%s: %d\n",str,ans);
    }
    return 0;
}

