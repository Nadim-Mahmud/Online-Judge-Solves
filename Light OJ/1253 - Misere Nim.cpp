#include<bits/stdc++.h>
#define chk(n,i) (bool)(n&(1<<i))
#define on(n,i) (n|(1<<i))
#define off(n,i) n=n&(~(1<<i))
#define ll long long
using namespace std;

int main()
{
    int i,j,k,n,m,x,cas=0,ts,c=0;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        c=0;
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            if(i==1) x = m;
            else x ^= m;
            if(m==1) c++;
        }
        if(c==n){
            if(n%2==0) printf("Case %d: Alice\n",cas);
            else printf("Case %d: Bob\n",cas);
        }
        else{
            if(x) printf("Case %d: Alice\n",cas);
            else printf("Case %d: Bob\n",cas);
        }
    }
    return 0;
}

