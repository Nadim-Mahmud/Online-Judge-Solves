#include<bits/stdc++.h>
#define p(XX) cout<<"db1: "<<XX<<endl;
#define pp(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
#define MX 10010
#define INF 1000000000000000
#define ll long long
using namespace std;

struct pii{
    ll v,w,mx;
    pii(){};
    pii(ll x,ll y,ll z){
        v=x,w=y,mx=z;
    }
};
bool operator<(pii a,pii b){
    return a.w>b.w;
}

struct dis{
    ll d,mx;
}lev[MX];
ll n,m,s,t,p,mn=-1,lev1[MX];
vector<ll>ed[MX],ec[MX];

ll dst(ll st){
    ll i,u,v,f,wt;
    priority_queue<pii>q;
    pii pr;
    q.push(pii(st,0,-1));
    lev[st].d=0;
    while(!q.empty()){
        pr = q.top();
        f = pr.v;
        q.pop();
        //if(lev[f].mx>pr.mx&&lev[f].d<pr.w) continue;
        if(f==t) mn = max(mn,pr.mx);
        for(i=0;i<ed[f].size();i++){
            v = ed[f][i];
            wt = pr.w + ec[f][i];
            if(wt>p) continue;
            if(lev[v].d>wt||(lev[v].d==wt&&lev[v].mx<pr.mx)){
                lev[v].d = wt;
                lev[v].mx = max(ec[f][i],pr.mx);
                q.push(pii(v,wt,lev[v].mx));
            }
            else if(pr.mx>lev1[v]||ec[f][i]>lev1[v]){
                lev1[v] = max(pr.mx,ec[f][i]);
                q.push(pii(v,wt,lev1[v]));
            }
        }
    }
    return mn;
}


void free(){
    ll i,j;
    mn=-1;
    for(i=0;i<MX;i++){
        lev[i].d = INF;
        lev[i].mx = -1;
        lev1[i]=-1;
        ed[i].clear();
        ec[i].clear();
    }
}
int  main(){
    ll i,j,k,ts,cas=0,u,v,w,ans;
   // freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        free();
        scanf("%lld %lld %lld %lld %lld",&n,&m,&s,&t,&p);
        for(i=1;i<=m;i++){
            scanf("%lld %lld %lld",&u,&v,&w);
            ed[u].push_back(v);
            ec[u].push_back(w);
        }
        ans = dst(s);
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
