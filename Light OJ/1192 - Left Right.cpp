#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum=0,i,cas=0,ts,n,a,b;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            sum ^= b-a-1;
        }
        if(sum) printf("Case %d: Alice\n",cas);
        else printf("Case %d: Bob\n",cas);
    }
    return 0;
}
