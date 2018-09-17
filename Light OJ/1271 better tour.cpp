#include<bits/stdc++.h>
#define p(XX) cout<<"db1 "<<XX<<endl;
#define p2(XX,YY) cout<<"db2 "<<XX<<" "<<YY<<endl;
using namespace std;

vector<int>ed[50005];
int vs[50005],lev[50005],dir[50005];


int bfs(int st,int en){
    int f,u,v,path,i;
    queue<int>q;
    q.push(st);
    vs[st] = 1;
    lev[st]=1;
    while(!q.empty()){
        f = q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++){
            v = ed[f][i];
            if(!vs[v]){
                vs[v] = 1;
                q.push(v);
                lev[v] = lev[f] + 1;
                dir[v] = f;
                if(v==en){
                    break;
                }
            }
        }
    }
    return path;
}

void free(){
    int i;
    for(i=0;i<=50005;i++){
        ed[i].clear();
        lev[i] = vs[i] = dir[i] = 0;
    }
}

int main()
{
    int i,j,k,l,m,n,ts,cas=0,x,y,st,mx=0;
    vector<int>vc;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            y = x;
            scanf("%d",&x);
            mx = max(x,mx);
            if(i==1){
                st=x;
                continue;
            }
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        for(i=1;i<=mx;i++){
            if(ed[i].size()!=0) sort(ed[i].begin(),ed[i].end());
        }
        bfs(st,x);
        m=x;
        while(m!=st&&m!=0){
            vc.push_back(m);
            m = dir[m];
        }
        vc.push_back(st);
        printf("Case %d:\n",cas);
        for(i=vc.size()-1;i>=0;i--){
            if(i==0) printf("%d\n",vc[i]);
            else printf("%d ",vc[i]);
        }
        vc.clear();
    }
    return 0;
}
