#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 10e-6;

using namespace std;

int ara[1000];


int main(){

    int i,j,t,cas=0,x,a,b,c,n,p,l,v,y;
    scanf("%d",&t);
    while(++cas <= t){
        c = 0;
        v=0;
        scanf("%d %d",&p,&l);
        a = p-l;
        c = 0;
        x = sqrt(a) + eps;
        printf("Case %d:",cas);
        if(a>l){
            for(i=1;i<=x;i++){
                if(a%i==0){
                    if(i>l){
                        printf(" %d",i);
                    }
                    y = a/i;
                    if(y>l&&i*i != a){
                        ara[++v] = y;
                    }
                }
            }
            for(i=v;i>0;i--) printf(" %d",ara[i]);
            printf("\n");
        }
        else printf(" impossible\n");
    }
    return 0;
}
