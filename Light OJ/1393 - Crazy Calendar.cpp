#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,n,m,x,ts,cas=0,ans;
    cin>>ts;
    while(++cas<=ts){
        ans = 0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&x);
                if((n-i+m-j)&1) ans ^= x;
            }
        }
        if(ans) printf("Case %d: win\n",cas);
        else printf("Case %d: lose\n",cas);
    }
    return 0;
}
