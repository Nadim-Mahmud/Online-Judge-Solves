#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,n,m,cn=0,ts,cas=0,sum;
    cin>>ts;
    while(++cas<=ts){
        cn=sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            if(m<0) cn++;
            sum += abs(m);
        }
        printf("Case %d: ",cas);
        if(cn==n) puts("inf");
        else{
            m = n-cn;
            cn = __gcd(sum,m);
            printf("%d/%d\n",sum/cn,m/cn);
        }
    }
    return 0;
}
