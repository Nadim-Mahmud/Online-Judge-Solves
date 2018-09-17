#include<bits/stdc++.h>
using namespace std;

vector<int>vc[105];
int vs[105],lev[105],n,m,odd;

void dfs(int u)
{
    if(vs[u]) return ;
    vs[u]=1;
    int i,v;
    for(i=0;i<vc[u].size();i++){
        v = vc[u][i];
        if(vs[v]&&(lev[u]+1)%2==1){
            cout<<u<<" "<<v<<" "<<lev[u]<<endl;
            odd = 1;
        }
        lev[v] = lev[u] + 1;
        cout<<u<<" "<<v<<endl;
        dfs(v);
    }
}

void free()
{
    int i;
    for(i=0;i<=102;i++){
        vc[i].clear();
        vs[i] = lev[i] = 0;
    }
    lev[1] = 1;
}

int main()
{
    int i,j,k,l,ts,cas=0,x,y,ans;
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            vc[x].push_back(y);
            vc[y].push_back(x);
        }
        odd=ans=0;
        dfs(1);
        for(i=1;i<=n;i++){
            if(lev[i]){
                if(odd==1) ans++;
                if(odd==0&&lev[i]%2==1) ans++;
            }
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
