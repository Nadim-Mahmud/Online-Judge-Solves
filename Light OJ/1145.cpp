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

vector <int> ed[105];
int lev[105],vs[105],nm,ans[105];
void bfs(int s){
    int i,j,d,f,v,cn=1;
    queue <int> q;
    q.push(s);
    lev[s]=1;
    vs[s]=1;
    while(!q.empty()){
        f=q.front();
        q.pop();
        if(f!=1) ans[s] = 1;
       // cout<<f<<endl;
        for(i=0;i<ed[f].size();i++){
            v=ed[f][i];
            if(!vs[v]){
                vs[v]=1;
                q.push(v);
                lev[v]=lev[f]+1;
                if(lev[v]%2) ans[v]=1;
            }
            else{
                if(lev[f]%2==0){
                    if(!ans[v]) ans[v]  = 2;
                }
            }
        }
    }
}

void clr(){
    for(int i=0;i<=102;i++){
        ed[i].clear();
        vs[i]=ans[i]=lev[i]=0;
    }
}

int main()
{
    int i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum;
    freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        clr();
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            ed[x].push_back(y);
           // ed[y].push_back(x);
        }
        bfs(1);
        sum=0;
        for(i=1;i<=n;i++){
            sum += ans[i];
        }
        printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
