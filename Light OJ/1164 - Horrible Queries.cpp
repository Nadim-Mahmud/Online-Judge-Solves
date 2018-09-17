#include<bits/stdc++.h>
#define ll long long
#define MX 100005
using namespace std;

ll seg[MX*4],lazy[MX*4];

void update(ll low,ll high,ll ulow,ll uhigh,ll val,ll pos)
{
    if(low>high) return ;
    if(lazy[pos]!=0){
        seg[pos] += (high-low+1)*lazy[pos];
        if(low!=high){
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(ulow>high||uhigh<low) return;
    //P2(low,high)
    if(ulow<=low&&uhigh>=high){
        seg[pos] += (high-low+1)*val;
        //cout<<seg[pos]<<endl;
        //P2(seg[pos],pos)
        if(low!=high){
            lazy[pos*2+1] += val;
            lazy[pos*2+2] += val;
        }
        return;
    }

    ll mid = (high+low)/2;

    update(low,mid,ulow,uhigh,val,pos*2+1);
    update(mid+1,high,ulow,uhigh,val,pos*2+2);
    seg[pos] = seg[pos*2+1] + seg[pos*2+2];
}

ll query(ll low,ll high,ll ulow,ll uhigh,ll pos)
{
    if(low>high) return 0;
    if(lazy[pos]!=0){
        seg[pos] += (high-low+1)*lazy[pos];
        if(low!=high){
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(ulow>high||uhigh<low) return 0;
    //P2(low,high)
    if(ulow<=low&&uhigh>=high)
        return seg[pos];

    ll mid = (high+low)/2;

    return query(low,mid,ulow,uhigh,pos*2+1) + query(mid+1,high,ulow,uhigh,pos*2+2);
}

int main()
{
    ll a,b,cas=0,ts,n,q,i,j,x,y,v;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%lld %lld",&n,&q);

        memset(seg,0,sizeof seg);
        memset(lazy,0,sizeof lazy);

        printf("Case %lld:\n",cas);

        for(i=1;i<=q;i++){
            scanf("%lld",&a);
            if(a==0){
                scanf("%lld %lld %lld",&x,&y,&v);
                update(0,n-1,x,y,v,0);
                //for(j=0;j<=30;j++) cout<<lazy[j]<<" ";
                //cout<<endl;
            }
            else{
                scanf("%lld %lld",&x,&y);
                x = query(0,n-1,x,y,0);
                //for(j=0;j<=30;j++) cout<<lazy[j]<<" ";
                //cout<<endl;
                printf("%lld\n",x);
            }
        }
    }
    return 0;
}
