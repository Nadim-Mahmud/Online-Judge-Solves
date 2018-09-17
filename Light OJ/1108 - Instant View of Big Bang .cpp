#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
#define MX 1010
#define INF 1000000000
using namespace std;

struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a,v=b,w=c;
    }
};

vector<edge>ed;
int n,m,q,lev[MX],mr[MX],rp[MX],vs[MX];

int belman(int sr){
    int i,j,k,ds,v,cn=0,u;
    lev[sr] = 0;
    for(i=1;i<=n;i++){
        cn=0;
        for(j=0;j<ed.size();j++){
            u = ed[j].u;
            v = ed[j].v;
            ds = lev[u] + ed[j].w;
            if(lev[v]>ds&lev[u]!=INF){
                vs[v] = 1;
                cn = 1;
                lev[v] = ds;
            }
        }
        if(!cn) break;
        if(i==n&&cn) return 1;
    }
    return 0;
}

void free(){
    int i;
    for(i=0;i<MX;i++){
        rp[i] = i;
        lev[i] = INF;
        mr[i] = vs[i] = 0;
    }
    ed.clear();
}

int rep(int n){
    if(rp[n]==n)return n;
    return rp[n]=rep(rp[n]);
}
void un(int a ,int b){
    if(rep(a)!=rep(b)) rp[rep(a)] = rep(b);
}

int main()
{
    int i,j,a,b,ts,cn=0,cas=0,x,y,w,sum,ans,v;
    freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        free();
        cn=ans=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            ed.push_back(edge(x,y,w));
            un(x,y);
        }
        for(i=0;i<n;i++){
            if(!vs[i]){
                vs[i]  = 1;
                cn = belman(i);
                if(cn){
                    mr[rep(i)] = 1;
                    ans = 1;
                }
            }
        }
        printf("Case %d: ",cas);
        if(!ans) puts("Impossible");
        else{
            v=0;
            for(i=0;i<n;i++){
                if(vs[rep(i)]) vs[++v] = i;
            }
            for(i=1;i<=v;i++){
                if(i==v) printf("%d\n",vs[i]);
                else printf("%d ",vs[i]);
            }
        }
    }
    return 0;
}
