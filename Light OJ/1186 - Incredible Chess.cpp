#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum=0,i,cas=0,ts,n,a,b,a1[105],b1[105],tmp;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a1[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&b1[i]);
        }
        for(i=1;i<=n;i++){
            sum ^= (b1[i]-a1[i]-1);
        }

        if(sum) printf("Case %d: white wins\n",cas);
        else printf("Case %d: black wins\n",cas);
    }
    return 0;
}

