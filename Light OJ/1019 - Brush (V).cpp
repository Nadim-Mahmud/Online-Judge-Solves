#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    int i,j,k,n,m,ara[105][105],ts,cas=0,x,y,w,a,b,c;
    cin>>ts;
    while(++cas<=ts){
        memset(ara,-1,sizeof ara);
        scanf("%d %d",&n,&m);

        for(i=1;i<=m;i++){
            scanf("%d %d %d",&x,&y,&w);
            if(ara[x][y]==-1) ara[x][y] = w;
            if(ara[y][x]==-1) ara[y][x] = w;
            ara[x][y] = min(w,ara[x][y]);
            ara[y][x] = min(w,ara[y][x]);
        }
        for(i=1;i<=n;i++) ara[i][i] = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(k=1;k<=n;k++){
                    a = ara[j][k];
                    b = ara[j][i];
                    c = ara[i][k];
                    if(a == -1) a = INF;
                    if(b == -1) b = INF;
                    if(c == -1) c = INF;
                    a = min(a,b+c);
                    if(a<INF) ara[j][k] = a;
                }
            }
        }
        if(ara[1][n]==-1) printf("Case %d: Impossible\n",cas);
        else printf("Case %d: %d\n",cas,ara[1][n]);
    }
    return 0;
}
