#include<bits/stdc++.h>
#define MX 10010
#define p(XX) cout<<"db1: "<<XX<<endl;
#define pp(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
#define pii pair<int,int>
using namespace std;

vector<int>ed[MX];
int vs[MX],dt[MX],low[MX],t=0,num,pr[MX],r;
bool art[MX];

void dfs(int n){
    int v,i,cn=0;
    low[n] = dt[n] = ++t;
    //pp(n,t)
    vs[n]=1;
    for(i=0;i<ed[n].size();i++){
        v = ed[n][i];
        if(pr[n]==v) continue;
        if(vs[v]) low[n] = min(low[n],dt[v]);
        else{
            pr[v]=n;
            dfs(v);
            low[n] = min(low[n],low[v]);
            if(dt[n]<=low[v]&&n!=r){
                art[n]=1;
            }
            cn++;
        }
    }
    if(cn>1&&n==r) art[n]=1;;
}


int free(){
    int i,cn=0;
    t=num=0;
    for(i=0;i<MX;i++){
        if(art[i])cn++;
        low[i] = dt[i] = vs[i] = art[i] = 0;
        pr[i]=-1;
        ed[i].clear();
    }
    return cn;
}

int main(){
    int n,i,j,u,v,ts,cas=0,x,m;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        r = v;
        dfs(r);
       // p(num);
        printf("Case %d: %d\n",cas,free());
    }
    return 0;
}
