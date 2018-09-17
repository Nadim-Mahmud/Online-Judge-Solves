#include<bits/stdc++.h>

using namespace std;
char str[105],dp[105][105];

int rec(int i,int j){

    if(i>=j) return 0;
    //cout<<str[i]<<" "<<cout<<str[j]<<endl;
    if(dp[i][j] != -1) return dp[i][j];
    int c1=0,c2=0;
    if(str[i]!=str[j]){
        c1 += 1 + rec(i,j-1);
        c2 += 1 + rec(i+1,j);
    }
    else return rec(i+1,j-1);
    return dp[i][j] = min(c1,c2);
}

int main(){

    int n,l,t,cas=0;
   // freopen("1033.txt","r",stdin);
    cin>>t;
    while(++cas<=t){
        memset(dp,-1,sizeof dp);
        scanf("%s",str);
        printf("Case %d: %d\n",cas,rec(0,strlen(str)-1));
    }
    return 0;
}
