#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){

    long long cas=0,t,x,y,m,c,l,i,j,c1,mx;

    while(1){

        scanf("%lld %lld",&x,&y);
        if(x==0&&y==0) break;

        c = 0;
        for(i=x;i<=y;i++){

            m = sqrt(i);
            if(m*m == i) c++;
        }

        printf("%lld\n",c);
    }
    return 0;
}


