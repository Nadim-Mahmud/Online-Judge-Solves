#include<bits/stdc++.h>
using namespace std;
int ara[53],dp[53][53];

int rec(int s,int e){

    if(e-s==1) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    //cout<<e<<endl;
    int cost=0,mini=10000,i;

    for(i=s+1;i<e;i++){
        cost = rec(s,i) + rec(i,e) - ara[s] + ara[e];
        mini = min(mini,cost);
    }
    return dp[s][e] = mini;
}

int main(){

    int i,j,n,h;
    while(1){
        memset(dp,-1,sizeof dp);
        scanf("%d",&h);
        if(h==0) break;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        ara[0] = 0;
        ara[n+1] = h;
        printf("The minimum cutting is %d.\n",rec(0,n+1));
    }
    return 0;
}
