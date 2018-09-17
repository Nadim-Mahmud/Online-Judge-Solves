#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[65][65];
char str[65];

void pr(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

ll pal(){
    int i,j,l,r,n;
    for(i=1;i<65;i++) dp[i][i] = 1;
    n = strlen(str+1);
    for(i=2;i<=n;i++){
        for(l=1;l+i-1<=n;l++){
            r = i + l - 1;
            if(str[l]==str[r]) dp[l][r] = dp[l+1][r] + dp[l][r-1] + 1;
            else dp[l][r] = dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1];
        }
    }
   // pr(n);
    return dp[1][n];
}

int main(){
    int i,j,k,ts,cas=0;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%s",str+1);
        printf("Case %d: %lld\n",cas,pal());
    }
    return 0;
}
