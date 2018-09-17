#include<bits/stdc++.h>

using namespace std;

int arr[6] = {50,25,10,5,1},dp[7][10000];

int coin(int i,int cs){

    int pr1=0,pr2=0;
    if(i>=5){
        if(cs == 0) return 1;
        else return 0;
    }
    if(cs<=10000&&dp[i][cs]!=-1) return dp[i][cs];
    else{
        if(cs-arr[i]>=0) pr1 = coin(i,cs-arr[i]);
        pr2 = coin(i+1,cs);

        if(cs<=10000) dp[i][cs] = pr1+pr2;
        return pr1+pr2;
    }
}

int main(){

    int m;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&m)==1){
        printf("%d\n",coin(0,m));
    }
    return 0;
}
