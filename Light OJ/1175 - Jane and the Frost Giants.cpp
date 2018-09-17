#include<bits/stdc++.h>
#define pii pair<int,int>
#define P(XX,YY) cout<<"db "<<XX<<" "<<YY<<endl;
#define MX 1000000000
using namespace std;

char str[205][205];
int n,m,vs[205][205],lev[205][205];
queue<pii>fr;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void show(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<str[i][j];
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

void fill(){
    int i,j,k,x,y,fx,fy;
    pii pr;
    while(!fr.empty()){
        pr = fr.front();
        fx = pr.first;
        fy = pr.second;
        fr.pop();
        if(fx==203&&fy==203){
            fr.push(pii(203,203));
            return;
        }
        for(i=0;i<4;i++){
            x = fx + dx[i];
            y = fy + dy[i];
            if(x>=0&&y>=0&&x<n&&y<m&&str[x][y]!='#'&&str[x][y]!='F'){
                str[x][y] = 'F';
                fr.push(pii(x,y));
            }
        }
    }
    fr.push(pii(203,203));
}

int bfs(int fx,int fy)
{
    int mi=MX,x,y,u,v,i,lv=0;
    queue<pii>q;
    pii pr;
    lev[fx][fy] = 1;
    vs[fx][fy] = 1;
    q.push(pii(fx,fy));
    //fill();
    while(!q.empty()){
        pr = q.front();
        fx = pr.first;
        fy = pr.second;
        q.pop();
        if(lv<lev[fx][fy]){
            lv = lev[fx][fy];
            fill();
            //show();
        }
        for(i=0;i<4;i++){
            x = fx + dx[i];
            y = fy + dy[i];
            if(x<0||y<0||x==n||y==m){
                mi = min(mi,lev[fx][fy]);
                continue;
            }
            if(str[x][y]=='#'||str[x][y]=='F'||str[x][y]=='J') continue;
           // P(x,y)
            if(!vs[x][y]){
                vs[x][y] = 1;
                lev[x][y] = lev[fx][fy] + 1;
                q.push(pii(x,y));
            }
        }
    }
    return mi;
}

void free()
{
    memset(vs,0,sizeof vs);
    memset(lev,0,sizeof lev);
    while(!fr.empty()) fr.pop();
}

int main()
{
    int i,j,k,ts,cas=0,ans,x,y;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(str[i][j]=='F'){
                    fr.push(pii(i,j));
                    //cout<<i<<" "<<j<<endl;
                }
                if(str[i][j]=='J'){
                    x = i;
                    y = j;
                }
            }
        }
        if(!fr.empty())fr.push(pii(203,203));
        //P(x,y);
        ans = bfs(x,y);
        if(ans==MX) printf("Case %d: IMPOSSIBLE\n",cas);
        else printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
