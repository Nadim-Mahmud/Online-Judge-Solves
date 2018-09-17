#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    long long cas=0,t,x,y,sum,c,l,i,j,c1,mx;

    while(scanf("%lld %lld",&x,&y) != EOF){

        mx  = 0;

        if(x<y) i=x,j=y;
        else i = y,j=x;

        for(i; i <= j; i++){

            l = i;
            c = 1;

            while(l>1){
                if(l%2 == 0) l /= 2,c++;
                else l = (3*l + 1)/2 , c += 2;
            }

            if(c>mx) mx = c;
        }
        printf("%lld %lld %lld\n",x,y,mx);
    }
    return 0;
}


