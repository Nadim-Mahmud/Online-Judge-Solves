#include<bits/stdc++.h>
using namespace std;

double ara[105],dp[105];
int n;

double gold(int i){
    if(i>n) return 0;
    if(dp[i]+98>0) return dp[i];
    int j,x=6;
    double r=ara[i];
    if(i+x>n) x = n-i;
    if(x==0) x=1;
    for(j=1;j<=6;j++){
        r += gold(i+j)/x;
    }
    return dp[i] = r;
}

int main(){
    int i,j,k,ts,cas=0;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        for(i=0;i<105;i++) dp[i] = -100;
        for(i=1;i<=n;i++){
            scanf("%lf",&ara[i]);
        }
        printf("Case %d: %.6lf\n",cas,gold(1));
    }
    return 0;
}
