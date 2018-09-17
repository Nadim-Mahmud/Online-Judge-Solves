#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[35][35];
ll dp1[35][35];
char str[35],st[35];
void pr(int n,int m);

int make(int n,int m)
  {
    int i,j;
    for(i=0;i<=34;i++){
        dp[i][0] = dp[0][i] = i;
        dp1[i][0] = dp1[0][i] = 1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(str[i-1]==st[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                dp1[i][j] = dp1[i-1][j-1];
            }
            else if(dp[i-1][j]==dp[i][j-1]){
                dp[i][j] = dp[i-1][j]+1;
                dp1[i][j] = dp1[i-1][j] + dp1[i][j-1];
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j] = dp[i][j-1] + 1;
                dp1[i][j] = dp1[i][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j] + 1;
                dp1[i][j] = dp1[i-1][j];
            }
        }
    }
    //pr(n,m);
    return dp[n][m];
}

int main(){
    int i,j,k,n,m,ts,cas=0;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%s %s",str,st);
        n = strlen(str);
        m = strlen(st);
        k = make(n,m);
        printf("Case %d: %d %lld\n",cas,k,dp1[n][m]);
    }
    return 0;
}


void pr(int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
