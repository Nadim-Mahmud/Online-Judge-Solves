#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,a,cs,x,y,n,m,c1,c2,ts,cas=0,trl,w;
    bool lt[105],rt[105];

    cin>>ts;
    while(++cas<=ts){
        c1=0,c2=0;
        memset(lt,0,sizeof lt);
        memset(rt,0,sizeof rt);
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&x,&y,&w);
            if(!lt[x]&&!rt[y]){
                lt[x] = rt[y] = 1;
                c1 += w;
            }
            else{
                lt[y] = rt[x] = 1;
                c2 += w;
            }
        }
        printf("Case %d: %d\n",cas,min(c1,c2));
    }
    return 0;
}

/*

vector <int> ed[105],ec[105],dir[105];
int lev[105],vs[105];
int bfs(int s){
    int i,j,d,f,v,mx=0;
    queue <int> q;
    q.push(s);
    lev[s]=0;
    while(!q.empty()){
        f=q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++){
            v=ed[f][i];
            if(!vs[v]){
                vs[v]=1;
                q.push(v);
                lev[v]=lev[f]+ec[f][i];
                dir[v].push_back(f);
            }
        }
        if(q.empty()) vs[f] = 0;
    }
}

void fill(){
    for(int i=0;i<=102;i++){
        ed[i].clear();
        ec[i].clear();
        dir[i].clear();
        lev[i] = 0;
        vs[i] = 0;
    }
}

*/
