#include<bits/stdc++.h>
using namespace std;
int dp[10010];

void grundy(){
    int i,j,mx;
    memset(dp,0,sizeof dp);
    set<int>s;
    for(i=3;i<10010;i++){
        s.clear();
        for(j=1;j+j<i;j++){
            //cout<<dp[j]<<" : "<<dp[i-j]<<endl;
            s.insert(dp[j]^dp[i-j]);
        }
        mx=0;
        while(s.find(mx)!=s.end()) mx++;
        dp[i]=mx;
       // cout<<i<<" "<<mx<<endl;
    }
}


int main(){
    int i,j,k,n,m,ts,cas=0,ans;
    grundy();
    cin>>ts;
    while(++cas<=ts){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&m);
            ans ^= dp[m];
        }
        if(ans) printf("Case %d: Alice\n",cas);
        else printf("Case %d: Bob\n",cas);
    }
    return 0;
}
