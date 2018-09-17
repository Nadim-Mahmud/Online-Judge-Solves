#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
using namespace std;

int ara[100005];
char st[100005];

int main()
{
    int i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum,in=0,c1=0,c2=0,c3=0;
    //freopen("test.txt","r",stdin);
    scanf("%s",st);
    j=1;
    i=0;
    while(st[i]){
        if(st[i]=='1')c2++;
        i++;
    }
    for(i=0;st[i];i++){
        if(st[i]=='0') c1++;
        //if(st[i]=='1') c2++;
        if(st[i]=='2') c3++;
        if((c3>0&&st[i+1]=='0')||st[i+1]=='\0'){
            while(1){
                if(c1) ara[++in] = 0,c1--;
                else if(c2) ara[++in] = 1,c2--;
                else if(c3) ara[++in] =2,c3--;
                else break;
            }
        }
    }
    for(i=1;i<=in;i++) printf("%d",ara[i]);
    cout<<endl;
    return 0;
}


