#include<bits/stdc++.h>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define ll long long
using namespace std;

ll dp[(1<<16)+2][20],ln,n,k;
ll ara[20];

ll bctk(int mask,ll val)
{
    if(mask==(1<<ln)-1) return (val==0);
    if(dp[mask][val]!=-1) return dp[mask][val];
    ll cnt=0,i;
    for(i=0;i<ln;i++){
        if(!(chk(mask,i))){
            cnt += bctk((on(mask,i)),(val*n+ara[i])%k);
        }
    }
    return dp[mask][val] = cnt;
}

int main(){
    int i,j,m,ts,cas=0;
    char str[20];
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        ln=0;
        memset(dp,-1,sizeof dp);
        scanf("%d %d %s",&n,&k,str);
        for(i=0;str[i];i++){
            ln++;
            if(str[i]<'A') ara[i] = str[i] - '0';
            else ara[i] = str[i] - 'A' + 10;
        }
        printf("Case %d: %lld\n",cas,bctk(0,0));
    }
    return 0;
}
