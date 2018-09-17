#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t.txt","w",stdout);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define eps 10e-7
#define MX 100005
using namespace std;

ll seg[MX*4],ul,uh,lazy[MX*4];

void update(ll l,ll h,ll val,ll pos)
{
    if(l>h) return;
    if(lazy[pos]!=-1){
        seg[pos] = (h-l+1)*lazy[pos];
        if(l!=h){
//            if(lazy[pos*2+1]==-1) lazy[pos*2+1] = 0;
//            if(lazy[pos*2+2]==-1) lazy[pos*2+2] = 0;
            lazy[pos*2+1] = lazy[pos];
            lazy[pos*2+2] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(ul>h||uh<l) return;
    if(ul<=l&&uh>=h){
        seg[pos] = (h-l+1)*val;
        if(l!=h){
//            if(lazy[pos*2+1]==-1) lazy[pos*2+1] = 0;
//            if(lazy[pos*2+2]==-1) lazy[pos*2+2] = 0;
            lazy[pos*2+1] = val;
            lazy[pos*2+2] = val;
        }
        return;
    }
    ll mid = (h+l)/2;
    update(l,mid,val,pos*2+1);
    update(mid+1,h,val,pos*2+2);
    seg[pos] = seg[pos*2+1] + seg[pos*2+2];
}

ll query(ll l,ll h,ll pos)
{
    if(l>h) return 0;
    if(lazy[pos]!=-1){
        seg[pos] = (h-l+1)*lazy[pos];
        if(l!=h){
//            if(lazy[pos*2+1]==-1) lazy[pos*2+1] = 0;
//            if(lazy[pos*2+2]==-1) lazy[pos*2+2] = 0;
            lazy[pos*2+1] = lazy[pos];
            lazy[pos*2+2] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(ul>h||uh<l) return 0;
    if(ul<=l&&uh>=h) return seg[pos];

    ll mid = (l+h)/2;

    return query(l,mid,pos*2+1) + query(mid+1,h,pos*2+2);
}



int main()
{
    ll i,j,a,b,ts,cn=0,cas=0,n,m,x,y,sum,q,v;
    //freopen("test.txt","r",stdin);
    scanf("%lld",&ts);
    while(++cas<=ts){
        scanf("%lld %lld",&n,&q);
        MS(seg,0)
        MS(lazy,-1)
        printf("Case %lld:\n",cas);
        for(i=1;i<=q;i++){
            scanf("%lld",&a);
            if(a==1){
                scanf("%lld %lld %lld",&ul,&uh,&v);
                update(0,n-1,v,0);
            }
            else{
                scanf("%lld %lld",&ul,&uh);
                a = query(0,n-1,0);
                x = uh-ul+1;
                if(a%x==0) printf("%lld\n",a/x);
                else{
                    b  = __gcd(x,a);
                    printf("%lld/%lld\n",a/b,x/b);
                }
            }
        }
    }
    return 0;
}

