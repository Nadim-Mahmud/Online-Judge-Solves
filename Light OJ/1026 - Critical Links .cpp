#include<bits/stdc++.h>
#define MX 10010
#define p(XX) cout<<"db1: "<<XX<<endl;
#define pp(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
#define pii pair<int,int>
using namespace std;

vector<int>ed[MX];
vector<pii>rec;
int vs[MX],dt[MX],low[MX],t=0,num,pr[MX];

void dfs(int n){
    int v,i;
    dt[n] = low[n] = ++t;
    vs[n] = 1;
    for(i=0;i<ed[n].size();i++){
        v = ed[n][i];
        if(pr[n]==v) continue;
        if(vs[v]) low[n] = min(low[n],dt[v]);
        else{
            pr[v] = n;
            dfs(v);
            low[n] = min(low[n],low[v]);
//            pp(n,v)
//            pp(dt[n],low[v])
//            p("ses\n")
            if(dt[n]<low[v]){
                rec.push_back(pii(min(n,v),max(n,v)));
            }
        }
    }
}


void free(){
    int i;
    t=num=0;
    for(i=0;i<MX;i++){
        low[i] = dt[i] = vs[i] = 0;
        pr[i]=-1;
        ed[i].clear();
    }
    rec.clear();
}

int main(){
    int n,i,j,u,v,ts,cas=0,x;
    char str[100];
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&u);
            scanf("%s",str);
            x = 0;
            for(j=1;str[j]!=')';j++){
                x = x*10 + (int)str[j] - '0';
            }
            for(j=1;j<=x;j++){
                scanf("%d",&v);
                ed[u].push_back(v);
            }
        }
        for(i=0;i<=n;i++){
            if(!vs[i]){
               // pp("source : ",i)
                dfs(i);
            }
        }
        sort(rec.begin(),rec.end());
        printf("Case %d:\n%d critical links\n",cas,rec.size());
        for(i=0;i<rec.size();i++){
            printf("%d - %d\n",rec[i].first,rec[i].second);
        }
    }
    return 0;
}
