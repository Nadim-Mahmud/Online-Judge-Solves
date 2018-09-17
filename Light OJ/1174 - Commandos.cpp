#include<bits/stdc++.h>
#define MX 105
using namespace std;

vector<int>ed[MX+5];
int ara[MX+5],arb[MX+5],c=0;
bool mark[MX+5];

void bfs(int s,int lev[])
{
    int f,v,i,mx=1;
    queue<int>q;
    memset(mark,0,sizeof mark);
    q.push(s);
    mark[s] = 1;
    lev[s] = 0;
    while(!q.empty())
    {
        f = q.front();
        q.pop();
        for(i=0;i<ed[f].size();i++)
        {
            v = ed[f][i];
            if(!mark[v])
            {
                q.push(v);
                mark[v] = 1;
                lev[v] += lev[f] + 1;
            }
        }
    }
    //return mx;
}

void fill()
{
    int i;
    for(i=0;i<=MX+2;i++){
        ed[i].clear();
        mark[i] = 0;
        ara[i] = 0;
        arb[i] = 0;
    }
}

int main()
{
    int t,cas=0,x,y,i,j,st,en,l,n,k,ans;
    cin>>t;
    while(++cas<=t)
    {
        fill();
        ans=0;

        scanf("%d",&l);
        scanf("%d",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        scanf("%d %d",&st,&en);
        bfs(st,ara);
        bfs(en,arb);

        for(i=0;i<=l;i++){
            ans = max(ans,(ara[i]+arb[i]));
            //cout<<ara[i]<<" "<<arb[i]<<endl;
        }

        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}

