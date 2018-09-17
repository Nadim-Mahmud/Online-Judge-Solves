#include<bits/stdc++.h>
#define MX 20002
using namespace std;

vector<int>ed[MX+5];
int lev[MX+5];
bool mark[MX+5];

int bfs(int s)
{
    int f,v,i,c1=1,c2=0;
    queue<int>q;

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
            if(!mark[v]){
                q.push(v);
                mark[v] = 1;
                lev[v] += lev[f] + 1;
                if(lev[v]&1) c2++;
                else c1++;
            }
        }
    }
    return max(c1,c2);
}

void fill()
{
    int i;
    for(i=0;i<=MX+2;i++){
        ed[i].clear();
        mark[i] = 0;
        lev[i] = 0;
    }
}

int main()
{
    int t,cas=0,x,y,i,j,sum,st,tm,n;
    cin>>t;
    while(++cas<=t)
{
        fill(),tm=0,st=0,sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);

            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        for(i=0;i<=MX;i++){
            if(!(ed[i].empty())&&mark[i] == 0){
                sum += bfs(i);
            }
        }

        printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
