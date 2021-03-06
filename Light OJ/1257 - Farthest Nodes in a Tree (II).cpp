#include<bits/stdc++.h>
#define MX 30002
using namespace std;

vector<int>ed[MX+5],cost[MX+5];
int lev[MX+5],lev2[MX+5];
bool mark[MX+5];

int bfs(int st){

    int i,j,f,v,mx,x;
    queue<int>q;
    q.push(st);

    memset(mark,0,sizeof mark);

    mark[st] = 1;
    lev[st] = 0;
    mx = st;
    while(!q.empty()){
        f = q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++){
            v = ed[f][i];
            if(!mark[v]){
                q.push(v);
                mark[v] = 1;
                lev[v] = lev[f] + cost[f][i];
                if(lev[v]>lev2[v]) lev2[v] = lev[v];
                //if(v==5) cout<<lev[v]<<" "<<" "<<f<<" "<<lev[f]<<" "<<cost[f][i]<<endl;
                if(lev[v]>lev[mx]) mx = v;
            }
        }
    }
    return mx;
}

void fill()
{
    int i;
    for(i=0;i<=MX+2;i++){
        cost[i].clear();
        ed[i].clear();
        mark[i] = 0;
        lev[i] = 0;
        lev2[i] = 0;
    }
}

int main()
{
    int t,cas=0,i,j,u,v,w,n,m,tm;
    //freopen("1257.txt","r",stdin);
    cin>>t;
    while(++cas<=t){

        fill();
        scanf("%d",&n);

        for(i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        tm = bfs(0);
        m = bfs(tm);
        tm = bfs(m);
        lev[tm] = lev[m];

        printf("Case %d:\n",cas);
        for(i=0;i<n;i++)
            printf("%d\n",lev2[i]);
    }
    return 0;
}
