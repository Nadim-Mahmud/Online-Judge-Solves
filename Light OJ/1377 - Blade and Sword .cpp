#include<bits/stdc++.h>
#define pii pair<int,int>
#define P(XX,YY) cout<<"db "<<XX<<" "<<YY<<endl;
#define MX 1000000000
using namespace std;

char str[205][205];
int n,m,vs[205][205],lev[205][205];
vector<pii>vc;
queue<pii>fr;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfsrev(int fx,int fy)
{
    int mn=MX,x,y,u,v,i,lv=0,j,cn=0;
    queue<pii>q;
    memset(vs,0,sizeof vs);
    memset(lev,0,sizeof lev);
    pii pr;
    lev[fx][fy] = 0;
    vs[fx][fy] = 1;
    q.push(pii(fx,fy));
    while(!q.empty()){
        pr = q.front();
        fx = pr.first;
        fy = pr.second;
        q.pop();
        for(i=3;i>=0;i--){
            x = fx + dx[i];
            y = fy + dy[i];
            if(str[x][y]=='#'||x<0||y<0||x>=n||y>=m) continue;
            if(!vs[x][y]){
                if(str[x][y]=='*'&&cn==0){
                    if(vc.size()==1) return MX;
                    for(j=0;j<vc.size();j++){
                        u = vc[j].first;
                        v = vc[j].second;
                        if(u==x&&v==y) continue;
                        vs[u][v] = 1;
                        lev[u][v] = lev[fx][fy] + 2;
                        //P(lev[u][v],"f**")
                        q.push(vc[j]);

                    }
                    cn=1;
                }
                //P(x,y)
                q.push(pii(x,y));
                vs[x][y] = 1;
                lev[x][y] = lev[fx][fy] + 1;
                if(str[x][y]=='*') lev[x][y] += 2;
                if(str[x][y]=='D') return lev[x][y];//mn = min(lev[x][y],mn);
            }
        }
    }
    return MX;
}



int bfs(int fx,int fy)
{
    int mn=MX,x,y,u,v,i,lv=0,j,cn=0;
    queue<pii>q;
    memset(vs,0,sizeof vs);
    memset(lev,0,sizeof lev);
    pii pr;
    lev[fx][fy] = 0;
    vs[fx][fy] = 1;
    q.push(pii(fx,fy));
    while(!q.empty()){
        pr = q.front();
        fx = pr.first;
        fy = pr.second;
        q.pop();
        for(i=0;i<4;i++){
            x = fx + dx[i];
            y = fy + dy[i];
            if(str[x][y]=='#'||x<0||y<0||x>=n||y>=m) continue;
            if(!vs[x][y]){
                if(str[x][y]=='*'&&cn==0){
                    if(vc.size()==1) return MX;
                    for(j=0;j<vc.size();j++){
                        u = vc[j].first;
                        v = vc[j].second;
                        if(u==x&&v==y) continue;
                        vs[u][v] = 1;
                        lev[u][v] = lev[fx][fy] + 2;
                        //P(lev[u][v],"f**")
                        q.push(vc[j]);

                    }
                    cn=1;
                }
                //P(x,y)
                q.push(pii(x,y));
                vs[x][y] = 1;
                lev[x][y] = lev[fx][fy] + 1;
                if(str[x][y]=='*') lev[x][y] += 2;
                if(str[x][y]=='D') return lev[x][y];//mn = min(lev[x][y],mn);
            }
        }
    }
    return MX;
}


int main()
{
    int i,j,k,ts,cas=0,ans,x,y;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(str[i][j]=='*') vc.push_back(pii(i,j));
                if(str[i][j]=='P'){
                    x = i;
                    y = j;
                }
            }
        }
        ans = bfs(x,y);
        ans = min(ans,bfsrev(x,y));
        if(ans==MX) printf("Case %d: impossible\n",cas);
        else printf("Case %d: %d\n",cas,ans);
        vc.clear();
    }
    return 0;
}
