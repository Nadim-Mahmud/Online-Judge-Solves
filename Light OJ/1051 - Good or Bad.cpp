#include<bits/stdc++.h>
using namespace std;
char str[55];
int dp[50][50][50],n,badmix;

///good 1;
///bad 2;
///mixed 3;

inline bool isvow(int i){
     if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U') return 1;
     return 0;
}

int rec(int i,int c,int v)
{
    if(c==5||v==3) return 2;
    if(i==n) return 1;

    if(dp[i][c][v] != -1) return dp[i][c][v];

    int st=0,st1,st2;

    if(isvow(i)) st = rec(i+1,0,v+1);
    else st = rec(i+1,c+1,0);
    if(str[i]=='?'){
        st1 = rec(i+1,c+1,0);
        st2 = rec(i+1,0,v+1);
        if(st1==1&&st2==1) st = 1;
        if((st1==1&&st2==2)||(st1==2&&st2==1)) st = 3;
        if(st1==2&&st2==2) st = 2;
        if(st1==3||st2==3) st = 3;
        //cout<<st1<<" "<<st2<<" "<<(st1|st2)<<" "<<st<<endl;
    }
    return dp[i][c][v] = st;
}

int main(){
    int i,j,ts,cas=0,c1=0,c2=0,x;
    //freopen("1051.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){

        memset(dp,-1,sizeof dp);
        scanf("%s",str);
        n = strlen(str);
        x = rec(0,0,0);
        if(x==1) printf("Case %d: GOOD\n",cas);
        else if(x==2) printf("Case %d: BAD\n",cas);
        else printf("Case %d: MIXED\n",cas);
    }
    return 0;
}
