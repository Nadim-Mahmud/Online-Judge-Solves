#include<iostream>
#include<cstdio>

using namespace std;

long long fn( int ara[], int n ) {
    long long sum = 0,i,c=0,x=0;
    for(i = n-1;i >= 0;i--){
        if(i < (n-1)) x += ara[i+1];//ara[i+1]+=ara[i+2];
        if(i != n){
            sum += ara[i]*c - x;
        }
        else sum += ara[i];
        c++;
    }
    return sum;
}

using namespace std;

int main(){

    long long i,cas=0,t,n,a,b,c,v,q,s,sum,x,j;
    int ara[100009];

    scanf("%lld",&t);
    while(++cas <= t){

        sum  = 0;
        c = 0;
        scanf("%lld %lld",&n,&q);
        printf("Case %lld:\n",cas);

        for(i=0;i<n;i++) scanf("%lld",&ara[i]);
        sum = fn(ara,n);
        for(i=1;i<=q;i++){
            scanf("%lld",&s);
            if(s==1){
                printf("%lld\n",sum);
            }
            else{
                scanf("%lld %lld",&x,&v);
                sum -= x*(v-ara[x]);
                sum += (n-x-1)*(v-ara[x]);
                ara[x] = v;
            }
        }
    }
    return 0;
}

