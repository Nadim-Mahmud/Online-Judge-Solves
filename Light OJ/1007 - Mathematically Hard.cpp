///lightoj 1007
#include<iostream>
#include<cstdio>

using namespace std;
//long long phi[5000005];
bool mark[5000006];
unsigned long long dp[5000006];

void phip(){

    int i,j;

    mark[1] = 1;
    dp[1] = 1;

    for(i=2;i<=5000005;i++){
        if(!mark[i]){
            for(j=i;j<=5000005;j+=i){
                if(!dp[j]) dp[j] = j;

                mark[j] = 1;
                dp[j] = dp[j]/i*(i-1);
            }
        }
        dp[i] = dp[i-1] + dp[i]*dp[i];
    }
}

int main(){

    unsigned long long cas=0,t,i,j,a,b,x;
    phip();
    //cout<<phi[5000000]<<" "<<dp[5000000]-dp[4999999]<<endl;
    cin>>t;
    while(++cas<=t){
        x = 0;
        scanf("%d %d",&a,&b);
        //cout<<dp[b]-dp[a-1]<<endl;
        printf("Case %d: ",cas);
        printf("%llu\n",dp[b]-dp[a-1]);
   }
    return 0;
}
