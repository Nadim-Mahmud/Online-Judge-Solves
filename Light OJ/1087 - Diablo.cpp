///not solved yet


#include <bits/stdc++.h>
#define ll long long
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define MX 150005
using namespace std;

int seg[MX*4],lazy[MX*4],ara[MX];

void update(int lw,int hi,int l,int h,int pos){

    if(lazy[pos]!=0){
        seg[pos] += lazy[pos];
        if(l!=h){
            lazy[pos*2]+=lazy[pos];
            lazy[pos*2+1]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(hi<l||lw>h) return;
    if(lw<=l&&hi>=h){
      //  P2(l,h)
        seg[pos]++;
        if(lw!=hi){
            lazy[pos*2]++;
            lazy[pos*2+1]++;
        }
        return;
    }
    int mid = (l+h)/2;

    update(lw,hi,l,mid,pos*2);
    update(lw,hi,mid+1,h,pos*2+1);
    seg[pos] += seg[pos*2] + seg[pos*2+1];
}

int query(int lw,int hi,int l,int h,int pos){
    if(lw>hi) return 0;
//     P2(l,h)
//     P(pos)
    if(lazy[pos]!=0){
//        P2(l,h)
        seg[pos] += lazy[pos];
        if(l!=h){
            lazy[pos*2]+=lazy[pos];
            lazy[pos*2+1]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(hi<l||lw>h) return 0;
    if(lw<=l&&hi>=h){
       // P2(l,h)
       // P(seg[pos])
        return seg[pos];
    }
    int mid = (l+h)/2;

    return max(query(lw,hi,l,mid,pos*2) , query(lw,hi,mid+1,h,pos*2+1));
}

int main(){
    int i,j,k,l,in=0,ts,cas=0,a,b,c,x,y,n,m,h;
    freopen("test.txt","r",stdin);
    char ch;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        in = 0;
        memset(seg,0,sizeof seg);
        memset(lazy,0,sizeof lazy);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[++in]);
        }
        printf("Case %d:\n",cas);
        h = n+m+3;
        for(i=1;i<=m;i++){
            scanf(" %c%d",&ch,&x);
            if('a'==ch){
                ara[++in] = x;
            }
            else{
                a = query(x,x,1,h,1);
               // P(a)
                if(ara[x+1]==-1){
                    b = query(x,h,1,h,1);
                    if(b>a){
                        update(x,x,1,h,1);
                    }
                }
                if(x+a>in){
                    printf("none\n");
                    continue;
                }
                else if(ara[x+a]==-1){
                    printf("none\n");
                    continue;
                }
                else printf("%d\n",ara[x+a]);
                ara[x+a] = -1;
                update(x,h,1,h,1);
            }
        }
    }
    return 0;
}


