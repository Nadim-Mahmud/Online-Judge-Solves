#include<iostream>
#include<cstdio>

using namespace std;

int ara[1000005],h;

int bins(int q){

    int l=0,m,ch=0;

    while(l<h){

        m = (l+h)/2;
        if(ara[m] > q) h = m-1;
        else if(ara[m]<q) l = m+1;
        else{
           ch = -1;
            break;
        }
    }
    if(ch) return m;
    else return -1;
}

int mian(){

    int x,y,i,j,c,k;

    while(1){
        scanf("%d %d",x,y);

        for(i=1;i<=x;i++){
            scanf("%d",ara[i]);
        }
        h = x;
        cout<<bins(2);
    }
    return 0;
}

