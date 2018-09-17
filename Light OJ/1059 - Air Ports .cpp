#include<bits/stdc++.h>
#define ll long long
#define MX 100002
using namespace std;

struct node{
    int u,v,w;
}st[MX+5];

int ara[MX+5];
ll m,n,in=0;

bool cmp(node a,node b){
    if(a.w<b.w) return 1;
    else return 0;
}

int rec(int n){
    if(ara[n]==n) return n;
    return ara[n] = rec(ara[n]);
}

int mst(){
    int i,u,v,cst=0,cnt=0;
    sort(st+1,st+in+1,cmp);
    for(i=0;i<=MX;i++) ara[i] = i;
    for(i=1;i<=in;i++){
        u = rec(st[i].u);
        v = rec(st[i].v);
        if(u!=v){
            ara[u] = v;
            cnt++;
            cst+=st[i].w;
            if(cnt==n) break;
        }
    }
    return cst;
}

int main(){
    ll i,j,k,a,b,x,y,cas=0,ts,cnt,ans;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        cnt=1;
        in=0;
        scanf("%lld %lld %lld",&n,&m,&a);
        for(i=1;i<=m;i++){
            in++;
            scanf("%d %d %d",&st[in].u,&st[in].v,&st[in].w);
            if(st[in].w>=a) in--;
        }
        ans = mst();
        b = rec(1);
        for(i=1;i<=n;i++){
            if(rec(i)!=b){
                cnt++;
                ara[rec(i)] = b;
            }
        }
        ans += a*cnt;
        printf("Case %lld: %lld %lld\n",cas,ans,cnt);
    }
    return 0;
}
