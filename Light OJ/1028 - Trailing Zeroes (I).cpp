#include<iostream>
#include<cstdio>
#include<cmath>
//#define mx 1000000

using namespace std;

bool mark[1000005];
int ara[80000],k=0;

void prime(){

    int i,j,lm=sqrt(1000000)+1;
    ara[++k] = 2;
    mark[1] = 1;
    for(i=4;i<=1000000;i+=2) mark[i] = 1;
    for(i=3;i<=1000000;i+=2){
        if(!mark[i]){
            ara[++k] = i ;
            if(i<=lm){
                for(j=i*i;j<=1000000;j+=(i<<1)) mark[j] = 1;
            }
        }
    }
}

int main(){

    int t,cas=0;
    long long c,n,i,m;
    prime();
    ara[k+1] = ara[k+2] = 0;
    //cout<<k;
    cin>>t;
    while(++cas<=t){

        scanf("%lld",&n);
        m = 1;
        for(i=1;ara[i]*ara[i]<=n&&i<=k;i++){
            c = 1;
            while(n%ara[i]==0) c++,n/=ara[i];
            //cout<<n<<" "<<c<<endl;
            m *= c;
        }
        if(n>1) m *= 2;
        printf("Case %d: %lld\n",cas,(m-1));
    }
    return 0;
}
