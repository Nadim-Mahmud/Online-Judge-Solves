#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
using namespace std;

vector<int> ed[1005];
bool mark[1005];

void siv(){
    int i,j,c=0;
    for(i=2;i<=1000;i++){
        if(!mark[i]){
           // cout<<i<<endl;
            //c++;
            for(j=i*i;j<=1000;j+=i){
                mark[j] = 1;
            }
        }
    }
    //cout<<c<<endl;
    for(i=4;i<=1005;i++){
        for(j=2;j<=i/2;j++){
            if(i%j==0&&!mark[j]) ed[i].push_back(j);
        }
    }
}
int n,t;
int lev[1005];
int bfs(int s){
    int i,j,f,v,mx = 0;
    queue<int>q;
    q.push(s);
    memset(lev,0,sizeof lev);
    lev[s] = 0;
    while(!q.empty()){
        f = q.front();
        //P(f)
        q.pop();
        if(f==t) return lev[f];
        for(i=0;i<ed[f].size();i++){
            v = f + ed[f][i];
            if(lev[v]==0&&v<=t){
                q.push(v);
                lev[v] = lev[f] + 1;
            }
        }
    }
    return -1;
}


int main()
{
    int i,j,a,b,ts,cn=0;
    siv();
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(ts--){
        scanf("%d %d",&n,&t);
        printf("Case %d: %d\n",++cn,bfs(n));
    }
    return 0;
}
