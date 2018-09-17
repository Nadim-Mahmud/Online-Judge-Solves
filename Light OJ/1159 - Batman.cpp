#include<bits/stdc++.h>
using namespace std;
char s1[55],s2[55],s3[55];
int dp[55][55][55];

int sec(int i,int j,int k)
{
    if(s1[i]=='\0'||s2[j]=='\0'||s3[k]=='\0') return 0;

    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans=0;
    if(s1[i]==s2[j]&&s2[j]==s3[k]) ans = 1 + sec(i+1,j+1,k+1);
    else{
        int v1,v2,v3,v4,v5,v6;
        v1 = sec(i+1,j,k);
        v2 = sec(i,j+1,k);
        //v3 = sec(i+1,j+1,k);
        v4 = sec(i,j,k+1);
        //v5 = sec(i+1,j,k+1);
        //v6 = sec(i,j+1,k+1);
        ans = max(v1,v2);
        ans = max(ans,v4);
        //ans = max(ans,v4);
        //ans = max(ans,v5);
        //ans = max(ans,v6);
    }
    return dp[i][j][k] = ans;
}

int main()
{
    int i,j,cas=0,ts,n;
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%s %s %s",s1,s2,s3);
        printf("Case %d: %d\n",cas,sec(0,0,0));
    }
    return 0;
}
