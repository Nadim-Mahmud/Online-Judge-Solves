#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int vis[22][22],lev[22][22],m,n,v=1;
char str[22][22];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int bfs(int fx,int fy){
    int x,y,i,mx=0;
    pii pi;
    queue<pii>q;
    q.push(pii(fx,fy));
    vis[fx][fy] = 1;
    lev[fx][fy] = 0;
    while(!q.empty()){
        pi = q.front();
        fx = pi.first;
        fy = pi.second;
        //cout<<fx<<"::"<<fy<<endl;
        q.pop();
        for(i=0;i<4;i++){
            x = fx + dx[i];
            y = fy + dy[i];
            if(!vis[x][y]&&str[x][y]!='#'&&str[x][y]!='m'&&(x>0 && y>0 && x<=m && y<=n)){
                q.push(pii(x,y));
                v++;
                vis[x][y] = 1;
                lev[x][y] = lev[fx][fy] + 1;
                //cout<<lev[x][y]<<endl;
                //cout<<x<<" "<<y<<endl;
                if(mx<lev[x][y] && (str[x][y]=='a'||str[x][y]=='b'||str[x][y]=='c')) mx = lev[x][y];
            }
        }
    }
    //cout<<v<<endl;
    return mx;
}

void fill()
{
    int i,j;
    for(i=0;i<=21;i++){
        for(j=0;j<=21;j++){
            str[i][j] = '0';
            vis[i][j] = 0;
            lev[i][j] = 0;
        }
    }
}

int main(){

    int i,j,ts,cas=0,x,y;
    //freopen("1238.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        fill();
        scanf("%d %d",&m,&n);
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                scanf(" %c",&str[i][j]);
                if(str[i][j] == 'h'){
                    x = i;
                    y = j;
                }
            }
        }
        //cout<<x<<" "<<y<<endl;
        //cout<<str[x][y]<<endl;
        printf("Case %d: %d\n",cas,bfs(x,y));
    }
}
