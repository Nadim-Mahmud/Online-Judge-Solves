#include<bits/stdc++.h>
#define INF 1000000000
#define p(XX) cout<<"db1: "<<XX<<endl;
#define pp(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
using namespace std;

vector<int>ed[210];
int n,m,q,lev[210],ara[210];

void belman(int sr){
    int i,j,k,ds,v;
    lev[1] = 0;
    for(i=1;i<n;i++){
        for(j=1;j<=n;j++){
            for(k=0;k<ed[j].size();k++){
                v = ed[j][k];
                ds = ara[v]-ara[j];
                ds = ds*ds*ds;
                if(lev[v]>lev[j]+ds&&lev[j]!=INF){
                    lev[v] = lev[j] + ds;
                }
            }
        }
    }
}
void free(){
    int i;
    for(i=0;i<=205;i++){
        lev[i] = INF;
        ed[i].clear();
    }
}

int main(){
    int  i,j,k,ts,cas=0,u,v,x;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            ed[u].push_back(v);
        }
        belman(1);
        scanf("%d",&q);
        printf("Case %d:\n",cas);
        for(i=1;i<=q;i++){
            scanf("%d",&x);
            if(lev[x]>=INF||lev[x]<3) printf("?\n");
            else printf("%d\n",lev[x]);
        }
    }
    return 0;
}
