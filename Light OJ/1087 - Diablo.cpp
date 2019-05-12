#include<bits/stdc++.h>
#define p(XX) cout<<XX<<endl;
#define pp(XX,YY) cout<<XX<<" "<<YY<<endl;
using namespace std;
#define MX 1000005

struct node{
    int dt,sum;
}seg[MX];

void update(int lw, int hi, int idx, int val, int pos){
    if(lw>hi) return;
    if(lw==hi){
        seg[pos].sum = (val>=0);
        seg[pos].dt = val;
        return;
    }
    int mid = (lw+hi)/2;
    //pp(lw,hi);
    if(mid>=idx){
        update(lw,mid,idx,val,pos*2);
    }
    else{
        update(mid+1,hi,idx,val,pos*2+1);
    }
    seg[pos].sum = seg[pos*2].sum + seg[pos*2+1].sum;
}


int query(int lw, int hi, int idx, int pos){
    if(lw>hi) return 0;
    seg[pos].sum--;
    //pp(seg[pos].sum,pos)
    if(lw==hi){
        return seg[pos].dt;
    }
    int mid = (lw+hi)/2;
    if(idx<=seg[pos*2].sum){
        return query(lw,mid,idx,pos*2);
    }
    else return query(mid+1,hi,idx-seg[pos*2].sum,pos*2+1);
}

int main(){
    int n,m,i,j,k,a,b,x,y,ts,cas=0,in;
    char ch;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        x = n+m+2;
        in=n;
        memset(seg,0,sizeof seg);
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            //pp(i,"-------------------")
            update(1,x,i,a,1);
        }
        printf("Case %d:\n",cas);
        for(i=1;i<=m;i++){
            scanf(" %c %d",&ch,&a);
            if(ch=='c'){
                if(a>seg[1].sum){
                    puts("none");
                }
                else{
                    printf("%d\n",query(1,x,a,1));
                }
            }
            else{
                in++;
                update(1,x,in,a,1);
            }
        }
    }
    return 0;
}
