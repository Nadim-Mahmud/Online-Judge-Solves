#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){

    int t,a,b,x,y,z,i;

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%d %d",&a,&b);

        x = abs(a - b);
        y = abs(a - 0);

        z = (x + y)*4 + 19;

        if( a==0 ) z =0;

        printf("Case %d: %d\n",i,z);
    }


    return 0;
}
