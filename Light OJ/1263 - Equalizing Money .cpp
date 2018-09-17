#include<bits/stdc++.h>
#define P(XX,YY) cout<<"db "<<XX<<" "<<YY<<endl;
using namespace std;

int ara[1005];
vector<int>vc[1005];
int vs[1005],no,n,m;

int bfs(int st)
{
    int mn,u,v,f,sum,i;
    queue<int>q;
    if(vs[st]) return 0;
    vs[st] = 1;
    q.push(st);
    sum = ara[st];
    while(!q.empty()){
        f = q.front();
        q.pop();
        no++;
//        P(no,"bal")
//        P(f,"sss")
        for(i=0;i<vc[f].size();i++){
            v = vc[f][i];
            if(!vs[v]){
                vs[v] = 1;
                q.push(v);
                sum += ara[v];
            }
        }
    }
    return sum;
}

void free()
{
    int i;
    for(i=0;i<=1003;i++){
        vc[i].clear();
        vs[i] = 0;
    }
}

int main()
{
    int i,j,ts,cas=0,x,y,tmp,avg,cn=0;
   // freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        cn=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d %d",&x,&y);
            vc[x].push_back(y);
            vc[y].push_back(x);
        }
        y=0;
        for(i=1;i<=n;i++){
            no=0;
            if(vs[i]) continue;
            tmp = bfs(i);
           // P(tmp,no)
            if(no>0){
                if(tmp%no) cn = 1;
                x = tmp/no;
            }
            if(0==y) y = x;
            if(y!=x) cn = 1;
        }
        if(cn) printf("Case %d: No\n",cas);
        else printf("Case %d: Yes\n",cas);
    }
    return 0;
}
