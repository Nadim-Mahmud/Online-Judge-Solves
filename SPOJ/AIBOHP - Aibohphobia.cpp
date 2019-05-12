#include<bits/stdc++.h>
using namespace std;

char str[7100];
int dp[6110][6110];

int solve(int st , int en)
{
    //cout<<st<<" "<<en<<endl;
    if(st>=en) return 0;
    if(dp[st][en]!=-1) return dp[st][en];
    int x = 0;
    if(str[st]==str[en]){
       // puts("sd");
        x = solve(st+1,en-1);
    }
    else{
        x = min(solve(st+1,en),solve(st,en-1))+1;
    }
   // cout<<x<<endl;
    return dp[st][en] = x;
}

int main(){
    int n,ts,cas=0;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        memset(dp,-1,sizeof dp);
        scanf("%s",str);
        printf("%d\n",solve(0,strlen(str)-1));
    }
    return 0;
}
