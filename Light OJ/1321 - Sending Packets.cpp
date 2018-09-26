#include<bits/stdc++.h>
#define MX 105
using namespace std;

double ara[MX][MX];

int main(){
    int n,m,l,ts,cas=0,s,k,u,v,c,i,j;
    double x,y,z;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d%d%d%d",&n,&m,&s,&k);

        memset(ara,0,sizeof ara);

        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&c);
            ara[u][v] = ara[v][u] = (double)c * 0.01;
        }

        for(i=0;i<n;i++) ara[i][i] = 1;

        for(l=0;l<n;l++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    ara[i][j] = max(ara[i][j],ara[i][l]*ara[l][j]);
                   // cout<<ara[i][j]<<endl;
                }
            }
        }
       // cout<<ara[0][n-1]<<endl;
        x = s*(k*2.0/ara[0][n-1]);

        printf("Case %d: %lf\n",cas,x);
    }
    return 0;
}
