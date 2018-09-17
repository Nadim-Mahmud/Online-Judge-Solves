#include<iostream>
#include<cstdio>
#define LL long long

using namespace std;

LL cntr(LL n,LL k){

    LL cnt=0,i=k;
    while(n>=i){
        cnt += n/i;
        //cout<<n<<i<<cnt<<endl;
        i *= k;
    }
    return cnt;
}

LL cnt(int n,int i){
    int cnt=0;
    while(n%i==0) cnt++,n/=i;
    return cnt;
}

int main(){

    LL i,z,cas=0,t,x,n,r,p,q,m,l;

    scanf("%lld",&t);

    while(++cas<=t){

        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);

        m = cntr(n,2),l = cntr(n,5);
        //cout<<m<<" "<<l<<endl;
        m -= cntr(r,2),l -= cntr(r,5);
        //cout<<m<<" "<<l<<endl;
        m -= cntr(n-r,2),l -= cntr(n-r,5);
        m += (cnt(p,2)*q),l += (cnt(p,5)*q);

        printf("Case %lld: %lld\n",cas,min(m,l));
    }
    return 0;
}

