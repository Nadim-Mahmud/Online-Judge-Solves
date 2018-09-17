#include<iostream>
#include<cstdio>

using namespace std;

int ara[1000005],x;

int bins(int q){

    int l=1,m,ch=0,h=x;

    while(h-l>=5){

        m = (l+h)/2;
        //cout<<m<<l<<h<<endl;
        if(ara[m] > q) h = m;
        else if(ara[m] <= q)l = m;
    }

    for(l;l<=h;l++){
        //cout<<l<<" "<<q<<endl;
        if(ara[l] == q){
            ch = -1;
            break;
        }
    }

    if(ch==-1) return 1;
    else return 0;
}

int main(){

    int y,i,j,c,k;

    while(1){
        scanf("%d %d",&x,&y);
        if(x==0&&y==0) break;

        for(i=1;i<=x;i++){
            scanf("%d",&ara[i]);
        }

        c = 0;
        for(i=1;i<=y;i++){
            scanf("%d",&k);
            c += bins(k);
            //cout<<k<<" "<<bins(k)<<endl;
        }
        //cout<<bins(7);

        printf("%d\n",c);
    }
    return 0;
}
