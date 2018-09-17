#include<bits/stdc++.h>
#define MX 50000
#define lm 100000005;
using namespace std;

int ax[MX+5],ay[MX+5],n;

int bnsx(int v){
    int lw=1,md,hi=n;
    while((hi-lw)>5){
        md = (lw+hi)/2;
        if(ax[md]>v) hi = md;
        else if(ax[md]<v) lw = md;
        else break;
    }
    //cout<<lw<<endl;
    for(lw;lw<=hi;lw++){
        if(ax[lw+1]>v) break;
    }
    while(ax[lw]>v)lw--;
    //cout<"---"<<lw<<endl;
    return min(lw,hi);
}

int bnsy(int v){
    int lw=1,md,hi=n;
    while((hi-lw)>5){
        md = (lw+hi)/2;
        if(ay[md]>v) hi = md;
        else if(ay[md]<v) lw = md;
        else break;
    }
    for(lw;lw<=hi;lw++){
        if(ay[lw+1]>v||ay[lw+1]==v) break;
    }
    while(ay[lw]>=v&&lw>0) lw--;
    //cout<<lw<<endl;
    return min(lw,hi);
}

int main(){
    int ts,i,j,k,cas=0,x,y;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%d %d",&ax[i],&ay[i]);
        }
        sort(ax+1,ax+n+1);
        sort(ay+1,ay+n+1);
        printf("Case %d:\n",cas);
        for(i=1;i<=k;i++){
            scanf("%d",&x);
            printf("%d\n",bnsx(x)-bnsy(x));
        }
    }
    return 0;
}
