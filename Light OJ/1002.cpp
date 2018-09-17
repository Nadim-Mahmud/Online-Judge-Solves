#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

struct edge{
    int u,v,w;
    edge(int u_,int v_,int w_){
        u = u_,v = v_,w = w_;
    }
};
bool operator < (edge a, edge b){
    return a.w > b.w;
}

int vs[505],ara[505];
vector<edge>ed[505];

void primsmst(int st)
{
    int i,j,k;
    priority_queue<edge>q;
    ara[st] = 0;
    vs[st] = 1;
    for(i=0;i<ed[st].size();i++){
        q.push(ed[st][i]);
    }
    while(!q.empty()){
        edge f = q.top();
        q.pop();
        if(!vs[f.v]){
            vs[f.v] = 1;
            ara[f.v] =  max(ara[f.u],f.w);
            for(i=0;i<ed[f.v].size();i++){
                if(!vs[ed[f.v][i].v]){
                    q.push(edge(ed[f.v][i].u,ed[f.v][i].v,ed[f.v][i].w));
                }
            }
        }
    }
}

void clr(){
    for(int i=0;i<=502;i++){
        ed[i].clear();
        vs[i] = 0;
        ara[i] = -1;
    }
}

int main()
{
    int i,j,k,tmp,ts,cas=0,u,v,w,n,m;
    freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        clr();
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            ed[u].push_back(edge(u,v,w));
            ed[v].push_back(edge(v,u,w));
        }
        scanf("%d",&u);
        primsmst(u);
        printf("Case %d:\n",cas);
        for(i=0;i<n;i++){
            if(ara[i]!=-1) printf("%d\n",ara[i]);
            else printf("Impossible\n");
        }
    }
    return 0;
}
