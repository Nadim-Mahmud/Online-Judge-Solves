#include<bits/stdc++.h>

using namespace std;

int nob(int n){

    int c=0;
    while(n>0){
        if(n&1) c ++;
        n = n>>1;
    }
    return c;
}

int hexa(int n){

    int x=0,c = 0;
    while(n>10){
        c += nob(n%10);
        n /= 10;
    }
    if(n>0) c+= nob(n);
    return c;
}

int main(){

    int d,h,n,c,cas=0,t;

    cin>>t;

    while(++cas <= t){

        c = 0;
        scanf("%d",&n);

        d = nob(n) ;
        h = hexa(n);

        printf("%d %d\n",d,h);
    }
    return 0;
}
