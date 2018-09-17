#include<bits/stdc++.h>
using namespace std;

vector<int>ed[105];
int odd[105],even[105],n,m;

void bfs(){
    int f,v,i,mr;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        f = q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++){
            v = ed[f][i];
            mr = 0;
            if(odd[v]&&even[v]) continue;
            if(!even[v]&&(f==1||odd[f])){
                even[v] = 1;
                mr=1;
            }
            else if(!odd[v]&&even[f]){
                odd[v] = 1;
                mr=1;
            }
            if(mr) q.push(v);
        }
    }
}


void free(){
    int i;
    for(i=0;i<=105;i++){
        ed[i].clear();
        odd[i] = even[i] = 0;
    }
}

int main(){
    int i,j,x,y,a,b,ts,cas=0,ans;
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        bfs();
        ans=0;
        for(i=1;i<=n;i++){
            if(odd[i]) ans++;
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
