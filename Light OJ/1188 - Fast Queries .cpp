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

void update(int low,int high,int ulow,int uhigh,int val,int pos)
{
    if(low>high) return ;
    if(ulow>high||uhigh<low) return;
    if(ulow<=low&&uhigh>=high){
        seg[pos] += val;
        return;
    }

    int mid = (high+low)/2;

    update(low,mid,ulow,uhigh,val,pos*2+1);
    update(mid+1,high,ulow,uhigh,val,pos*2+2);
    seg[pos] = seg[pos*2+1] + seg[pos*2+2];
}

int query(int low,int high,int qlow,int qhigh,int pos)
{
    if(low>high) return 0;
    if(qlow>high||qhigh<low) return 0;
    if(qlow<=low&&qhigh>=high)
        return seg[pos];
    int mid = (high+low)/2;
    return query(low,mid,qlow,qhigh,pos*2+1) + query(mid+1,high,qlow,qhigh,pos*2+2);
}


int main(){
    int i,j,k,n,m,ts,cas=0,x,y,in;
    pii pi;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts)
    {
        scanf("%d %d",&n,&m);
        memset(last,-1,sizeof last);
        memset(seg,0,sizeof seg);
        in = 1;
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
           // cout<<ara[i]<<" ";
        }
        for(i=1;i<=m;i++){
            scanf("%d %d",&st[i].a,&st[i].b);
            st[i].c = i;
        }
        sort(st+1,st+m+1,cmp);
        in=1;
        for(i=1;i<=n;i++){
           // p(i)
            if(last[ara[i]]!=-1){
                update(1,n,last[ara[i]],last[ara[i]],-1,1);
            }
            last[ara[i]] = i;
            update(1,n,i,i,1,1);
            while(i==st[in].b){
               // p(st[in].b)
                st[in].d = query(1,n,st[in].a,st[in].b,1);
                st[in].b = st[in].c;
                in++;
            }
        }
        sort(st+1,st+m+1,cmp);
        printf("Case %d:\n",cas);
        for(i=1;i<=m;i++){
            printf("%d\n",st[i].d);
        }
    }
    return 0;
}
