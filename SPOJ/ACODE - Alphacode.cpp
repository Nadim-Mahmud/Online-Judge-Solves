#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 5005

ll dp[MX],n;
char st[MX];

ll ways(ll pos){

    if(pos>=n) return 1;

    if(dp[pos]!=-1) return dp[pos];

    ll x=0,y=0;
    x = ways(pos+1);
    y = (int)(st[pos] - '0')*10 + (int)(st[pos+1]- '0');
    //cout<<pos<<" "<<y<<endl;
    if(pos<n-1&&y>=1&&y<=26){
        x += ways(pos+2);
    }
    //cout<<pos<<" "<<x<<endl;
    return dp[pos] = x;
}

int main(){
    ll i,j,k,m,in=0;
    //freopen("test.txt","r",stdin);
    while(scanf("%s",st)&&st[0]!='0'){
        memset(dp,-1,sizeof dp);
        in=0;
        for(i=0;st[i];i++){
            if(st[i+1]=='0'){
                st[in++] = 'z';
                i++;
            }
            else st[in++] = st[i];
        }
        n = in;
        st[in] = '\0';
        //cout<<st<<endl;
        printf("%lld\n",ways(0));
    }
    return 0;
}
