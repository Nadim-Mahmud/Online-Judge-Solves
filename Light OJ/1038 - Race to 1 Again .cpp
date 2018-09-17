#include<bits/stdc++.h>
#define MX 100010
#define eps 10e-6
using namespace std;

double ara[MX];

void prec(){
    int i,cn=0,x,k,a,b,r,st[800],v,j;
    double tmp;
    ara[1] = 0;
    for(i=2;i<=MX;i++){
        r = sqrt(i)+eps;
        v=cn=0;
        for(j=1;j<=r;j++){
            if(i%j==0){
                cn+=2;
                st[++v] = j;
                if(i!=j*j)st[++v] = i/j;
                else --cn;
            }
        }
        ara[i]=tmp=0.0;
        for(k=1;k<=v;k++){
            tmp += (ara[st[k]]+1.0)/(double)cn;
        }
        ara[i] = tmp/((double)(cn-1)/(double)cn);
    }
}


int main(){
    int i,j,k,l,m,cas=0,ts,n;
    prec();
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        printf("Case %d: %.8lf\n",cas,ara[n]);
    }
    return 0;
}
