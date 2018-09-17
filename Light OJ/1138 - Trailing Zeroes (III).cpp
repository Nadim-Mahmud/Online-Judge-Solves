#include<iostream>
#include<cstdio>


using namespace std;


long long zero(long long n){

    long long sum=0,c=0,i,x;
    for(x=5;x<=n;x*=5){
        sum += n/x;
    }
    return sum;
}

long long biseq(long long n,long long l,long long h){

    long long i,c,x,m;
    m = ((((l+h)/2)/5)*5);
    while(l<h){
        x = zero(m);
        if(x == n) return m;
        if(l==m) return -1;
        //cout<<l<<" "<<m<<" "<<h<<" "<<x<<endl;
        if(n < x){
            h = m;
            m = ((((l+h)/2)/5)*5);
        }
        if(n > x){
            l = m;
            m = ((((l+h)/2)/5)*5)+5;
        }
    }
}


int main(){

    long long i,z,n,cas=0,t,x;
    //freopen("1138.txt","r",stdin);

    scanf("%lld",&t);
    while(++cas<=t){
        scanf("%lld",&n);
        for(i=5;;i*=5){
            if(zero(i) > n) break;
        }
        x = biseq(n,i/5,i);

        if(x==-1) printf("Case %lld: impossible\n",cas);
        else printf("Case %lld: %lld\n",cas,x);
    }
    return 0;
}
