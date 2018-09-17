#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum=0,i,j,cas=0,ts,n,a,b,m,tmp;
    cin>>ts;
    while(++cas<=ts){
        sum=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            tmp=0;
            for(j=1;j<=m;j++){
                scanf("%d",&a);
                tmp+=a;
            }
            sum ^= tmp;
        }
        if(sum) printf("Case %d: Alice\n",cas);
        else printf("Case %d: Bob\n",cas);
    }
    return 0;
}

