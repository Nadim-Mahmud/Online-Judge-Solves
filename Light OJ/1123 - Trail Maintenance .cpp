#include<bits/stdc++.h>
#define ll long long
#define MX 201
using namespace std;

struct node{
    int u,v,w;
    bool operator < (const node &a) const {
        return w<a.w;
    }
}st[MX+5];

int ara[MX+5];
int m,n,in=0,cnt;

int rec(int n){
    if(ara[n]==n) return n;
    return ara[n] = rec(ara[n]);
}

int mst(){
    int i,u,v,cst=0,rem=-1;
    cnt=0;
    sort(st,st+in);
    for(i=0;i<=n;i++) ara[i] = i;
    for(i=0;i<in;i++){
        u = rec(st[i].u);
        v = rec(st[i].v);

        if(u==v){
            rem = i;
            continue;
        }
        ara[u] = v;
        cnt++;
        cst+=st[i].w;
    }
    if(rem!=-1) st[rem] = st[--in];
    if(n-1==cnt) return cst;
    return -1;
}

int main(){
    int i,j,k,a,b,x,y,cas=0,ts,ans;
    //freopen("test.txt","r",stdin);
    scanf("%d",&ts);
    while(++cas<=ts){
        in=0;
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",cas);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&st[in].u,&st[in].v,&st[in].w);
            in++;
            printf("%d\n",mst());
        }
    }
    return 0;
}
