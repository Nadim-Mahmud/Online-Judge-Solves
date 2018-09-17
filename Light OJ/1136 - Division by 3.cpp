#include<iostream>
#include<cstdio>

using namespace std;

int fn(int b){

    int z;

    if((b-1)%3 == 0) z = 0;
    else z = 1;

    return z;
}

int main(){

    long long  a,b,t,i,x,y,z;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%lld %lld",&a,&b);

        if((b-a)==0){

            z = fn(a);

        }
        else{

            x = (b-a) + 1 ;

            y = x%3;

            if(y > 1){
                y = y - 1;
            }
            else y = 0;

            z = (x/3)*2 + y;
        }

        printf("Case %lld: %lld\n",i,z);
    }

    return 0;
}
