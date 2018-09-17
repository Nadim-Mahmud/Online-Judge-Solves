#include<bits/stdc++.h>

using namespace std;

int dp[1005][3005],p[1005],wt[1005],cap,n;

int nsp(int i,int w){

    //cout<<i<<" "<<w<<endl;
    int pr1,pr2;
    if(i == n+1) return 0;

    if(i<=1000&&w<=3000&&dp[i][w]!=-1) return dp[i][w];
    else{
        if(w+wt[i]<=cap){
            pr1 = p[i] + nsp(i+1,w+wt[i]);
        }
        else pr1 = 0;
        pr2 = nsp(i+1,w);
        return dp[i][w] = max(pr1,pr2);
    }
}

int main(){

    int cas=0,t,g,a,i,ans;
    cin>>t;
    while(++cas<=t){
        ans = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&p[i],&wt[i]);
        }
        scanf("%d",&g);
        for(i=1;i<=g;i++){
            memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            ans += nsp(1,0);
            //cout<<nsp(1,0)<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
