#include<bits/stdc++.h>
#define MX 10000
using namespace std;

vector<int>ed[MX+5];
int vs[MX+5],n,m,ind[MX+5];

void dfs(int u){
    if(vs[u]) return;
    vs[u] = 1;
    for(int i=0;i<ed[u].size();i++){
        dfs(ed[u][i]);
    }
    vs[u] = 2;
}

void free();
int main()
{
    int i,j,k,ts,cas=0,u,v=0,c;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        c=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            ed[u].push_back(v);
            ind[v]++;
        }
        for(i=1;i<=n;i++){
            if(ind[i]==0){
                c++;
                dfs(i);
            }
        }
        for(i=n;i>0;i--){
            if(vs[i]==0){
                c++;
                dfs(i);
            }
        }
        printf("Case %d: %d\n",cas,c);
    }
    return 0;
}

void free(){
    for(int i=0;i<=MX+1;i++){
        ed[i].clear();
        vs[i]=0;
        ind[i]=0;
    }
}
