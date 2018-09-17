#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
#define pii pair<int,int>
using namespace std;

int vs[12][12],lev[12][12],n,a,b,trk[12][12],c;
char  ar[12][12],tmp;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int bfs(int fx,int fy)
{
    int i,v,x,y,mx=0;
    queue <pii> q;
    pii pr;
    memset(vs,0,sizeof vs);
    vs[fx][fy]=1;
    lev[fx][fy]=0;
    q.push(pii(fx,fy));
    while(!q.empty()){
        pr=q.front();
        fx=pr.first;
        fy=pr.second;
        q.pop();
        for(i=0;i<4;i++){
            x=fx+dx[i];
            y=fy+dy[i];
            //cout<<"fff\n";
            if(x<=0||x>n||y<=0||y>n||ar[x][y]=='#')continue;
           // cout<<tmp<<" "<<x<<" "<<y<<" "<<ar[x][y]<<endl;
            if(!vs[x][y]&&(ar[x][y] == '.'|| ar[x][y] == tmp || trk[x][y] == 1)){
                //cout<<tmp<<endl;
                q.push(pii(x,y));
                vs[x][y]=1;
                lev[x][y]=lev[fx][fy]+1;
                //cout<<lev[x][y]<<" "<<x<<" "<<y<<endl;
                if(ar[x][y] == tmp) return lev[x][y];
                //if(lev[x][y]>mx&& ar[x][y]>='A' && ar[x][y] <= 'Z') mx = lev[x][y];
            }
        }

    }
    return 0;
    //return mx;
}

void fill()
{
    for(int i=0;i<=11;i++){
        for(int j=0;j<=11;j++){
            //ar[i][j] = 0;
            lev[i][j] = 0;
            vs[i][j] = 0;
            trk[i][j] = 0;
        }
    }
}

int main()
{
    int i,j,ts,cn=0,x,y;
    //freopen("1066.txt","r",stdin);
    scanf("%d",&ts);
    while(ts--){
        fill(),c=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf(" %c",&ar[i][j]);
                if(ar[i][j]>='A'&&ar[i][j]<='z'){
                    c++;
                }
            }
        }
        char rmp = 'A';
        int tr=1,sum=0,mr=0;
        a = 0;
        while(++tr<=c){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    //cout<<ar[i][j]<<" : "<<rmp<<endl;
                    if(ar[i][j] == rmp){
                        //P(rmp)
                        tmp = rmp + 1;
                        trk[i][j] = 1;
                        a = bfs(i,j);
                        //cout<<"a: "<<a<<endl;
                        if(a == 0) mr = 1,tr=1000;
                        sum += a;
                        //cout<<sum<<endl;
                        i=100,j=100;
                    }
                }
            }
            rmp += 1;
        }
        //cout<<sum<<endl;

        if(mr!=1) printf("Case %d: %d\n",++cn,sum);
        else printf("Case %d: Impossible\n",++cn);
    }
    return 0;
}
