#include<bits/stdc++.h>
#define pii pair<int,int>
#define p(XX) cout<<XX<<endl;
#define pp(XX,YY) cout<<XX<<" "<<YY<<endl;
using namespace std;
#define MX 100005

int ara[MX],last[MX],seg[MX*4];

struct node{
    int a,b,c,d;
}st[MX];

bool cmp(node x,node y){
    return x.b<y.b;
}

void update(int lw,int hi,int q,int v,int pos){
//    pp(lw,hi);
//    p(v)
    if(lw>hi) return;
    if(q==lw&&q==hi){
        seg[pos]+=v;
        return;
    }
    int mid = (lw+hi)/2;
    if(q<=mid){
        update(lw,mid,q,v,pos*2);
    }
    else{
        update(mid+1,hi,q,v,pos*2+1);
    }
}


int query(int lw, int hi, int qlw, int qhi, int pos){
//    p(lw)
    if(lw>hi) return 0;
    if(lw>qhi||hi<qlw) return 0;
    if(qlw<=lw&&qhi>=hi){
        return seg[pos];
    }
    int mid = (lw+hi)/2;
    return query(lw,mid,qlw,qhi,pos*2) + query(mid+1,hi,qlw,qhi,pos*2+1);
}


int main(){
    int i,j,k,n,m,ts,cas=0,x,y,in;
    pii pi;
    freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts)
    {
        scanf("%d %d",&n,&m);
        memset(last,-1,sizeof last);
        memset(seg,0,sizeof seg);
        in = 1;
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
            cout<<ara[i]<<" ";
        }
        for(i=1;i<=m;i++){
            scanf("%d %d",&st[i].a,&st[i].b);
            st[i].c = i;
        }
        sort(st+1,st+m+1,cmp);
        p("ss")
        for(i=1;i<=n;i++){
            p(i)
            if(last[ara[i]]!=-1){
                update(1,n,last[ara[i]],-1,1);
                pp("ss ",i)
            }
            last[ara[i]] = i;
            update(1,n,i,1,1);

            while(ara[i]==st[in].b){
                st[in].d = query(1,n,st[in].a,st[in].b,1);
                st[in].b = st[in].c;
                in++;
            }
        }
        sort(st+1,st+m+1,cmp);
        printf("Case %d:\n",cas);
        for(i=1;i<=n;i++){
            printf("%d\n",st[i].d);
        }
    }
    return 0;
}
