#include<bits/stdc++.h>
#define p1(XX) cout<<"db1: "<<XX<<endl;
#define p2(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
#define mx 100000
using namespace std;

int n,m,ara[4*mx+5][4],lazy[4*mx+5];

void create(int l,int h,int pos){
    if(l==h){
        ara[pos][0] = 1;
        ara[pos][1] = ara[pos][2] = 0;
        return;
    }
    int mid = (l+h)/2;
    create(l,mid,pos*2+1);
    create(mid+1,h,pos*2+2);
    ara[pos][0] = ara[pos*2+1][0] + ara[pos*2+2][0];
    ara[pos][1] = ara[pos][2] = 0;
}

void update(int l,int h,int ul,int uh,int pos){
    if(uh<l||ul>h) return;
    int tmp[4];
    if(ul<=l&&uh>=h){
        tmp[0] = ara[pos][0];
        tmp[1] = ara[pos][1];
        tmp[2] = ara[pos][2];
        ara[pos][0] = tmp[2];
        ara[pos][1] = tmp[0];
        ara[pos][2] = tmp[1];
        lazy[pos]++;
        return;
    }
    int mid = (l+h)/2;
    update(l,mid,ul,uh,pos*2+1);
    update(mid+1,h,ul,uh,pos*2+2);
    ara[pos][0] = ara[pos*2+1][0] + ara[pos*2+2][0];
    ara[pos][1] = ara[pos*2+1][1] + ara[pos*2+2][1];
    ara[pos][2] = ara[pos*2+1][2] + ara[pos*2+2][2];
    tmp[0] = ara[pos][0];
    tmp[1] = ara[pos][1];
    tmp[2] = ara[pos][2];
    ara[pos][(0+lazy[pos])%3] = tmp[0];
    ara[pos][(1+lazy[pos])%3] = tmp[1];
    ara[pos][(2+lazy[pos])%3] = tmp[2];
}

int query(int l,int h,int ul,int uh,int pos,int cr=0){
   // p2(l,h)
    //p2(ul,uh)
    int tmp[4];
    if(uh<l||ul>h) return 0;
    if(ul<=l&&h<=uh){
      //  p1("sdfd")
        if((2+cr)%3==0) return ara[pos][2];
        if((1+cr)%3==0) return ara[pos][1];
        if((0+cr)%3==0) return ara[pos][0];
    }
    int mid = (l+h)/2;
    return query(l,mid,ul,uh,pos*2+1,cr+lazy[pos]) + query(mid+1,h,ul,uh,pos*2+2,cr+lazy[pos]);

}

int main(){
    int i,j,k,ts,cas=0,b,x,y;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        memset(lazy,0,sizeof lazy);
        create(0,n-1,0);
        printf("Case %d:\n",cas);
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&b,&x,&y);
            if(b==0){
                update(0,n-1,x,y,0);
            }
            else{
               // p2("up: ",i)
                printf("%d\n",query(0,n-1,x,y,0));
            }
        }
    }
    return 0;
}
