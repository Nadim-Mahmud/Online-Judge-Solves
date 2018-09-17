#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int t,k,x,y,n,c,i,a;
    cin>>t;
    for(k=1;k<=t;k++){
        scanf("%d",&n);
        c = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            if(i==1){

                if(x>2){
                    if((x-2)%5 == 0) c += x/5;
                    else c += ((x-2)/5 + 1);
                }
                y = x;
                continue;
            }
            a = x-y;
            if(a%5 == 0) c += a/5;
            else c += (a/5 + 1);
            y = x;
        }
        printf("Case %d: %d\n",k,c);
    }
    return 0;
}
