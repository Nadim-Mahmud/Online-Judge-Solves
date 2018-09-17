#include<iostream>
#include<cstdio>

using namespace std;

long fn(long x,long y){

    if(x>y) return(x-y);
    else return (y-x);
}

int main(){

    long x1,x2,y1,y2,z1,z2,a,b,c,p,q,r,t,i,j,c1,n,volume;

    cin>>t;

    for(i = 1;i<=t;i++){

        a = 0; b = 0; c = 0; p = 0; q = 0; r = 0;
        c1 = 0;
        volume = 0;

        scanf("%ld",&n);

        for(j=1 ; j<=n ; j++){

            scanf("%ld %ld %ld  %ld %ld %ld",&x1,&y1,&z1,&x2,&y2,&z2);

            if(j == 1){
                a = x1;
                b = y1;
                c = z1;
                p = x2;
                q = y2;
                r = z2;
            }
            if((x1>a&&x1>p) || (x1<a&&x2<a)) c1++;


            if(x1>a) a = x1;
            if(y1>b) b = y1;
            if(z1>c) c = z1;
            if(x2<p) p = x2;
            if(y2<q) q = y2;
            if(z2<r) r = z2;
        }

        volume = fn(a,p)*fn(b,q)*fn(c,r);

        if(c1 != 0) volume = 0;

        printf("Case %ld: %ld\n",i,volume);
    }
    return 0;
}
