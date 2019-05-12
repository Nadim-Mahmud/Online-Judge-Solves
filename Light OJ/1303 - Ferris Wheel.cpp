#include<bits/stdc++.h>
#define map map<int,bool>
#define pii pair<int,int>
#define piix pair<int,pii>
#define p(XX) cout<<XX<<endl;
#define pp(XX,YY) cout<<XX<<" "<<YY<<endl;
using namespace std;

queue<pii>q;
deque<int>dq;
int mr[25][25];

int next(int n){
    int x = dq.front(),tmp,y;
    tmp = x;
    if(dq.size()==0) return 0;
    while(mr[x][n]){
        dq.push_back(x);
        dq.pop_front();
        x = dq.front();
        if(x==tmp){
            return 0;
        }
    }
    y = x;
    //p(dq.size())
    dq.pop_front();
    if(y!=tmp){
        while(tmp!=y){
            y = dq.back();
            dq.pop_back();
            dq.push_front(y);
        }
    }
    mr[x][n] = 1;
    mr[x][0]++;
    return x;
}

void init(int  n, int m){
    while(!q.empty()) q.pop();
    dq.clear();
    memset(mr,0,sizeof mr);
    for(int i=1;i<=m;i++){
        q.push(pii(i,0));
    }
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
}

int main()
{
    int cas=0,ts,i,j,k,l,n,m,sum,mult,mc=0,cn,cnt,x;
    pii pi ;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        init(n,m);
        cn=cnt=0;
        while(cnt<n*m){
            pi = q.front();
            q.pop();
            //p(cnt)
            x = pi.second;
           // pp("namlo",x)
            if(x!=0){
                cnt++;
                //pp("ys",x)
               // if(cnt==n*m) break;
                if(mr[x][0]<m){
                   // p(dq.size())
                    dq.push_back(x);
                    //p(dq.size())
                   // pp(dq.front(),x);
                }
            }
            pi.second = next(pi.first);
           // pp(pi.first, pi.second);
            q.push(pi);
            cn+=5;
            //if(cn>100) break;
        }
        printf("Case %d: %d\n",cas,cn);
    }
    return 0;
}
