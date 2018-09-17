#include<bits/stdc++.h>
using namespace std;

int grundy(int n){
    if(n%2==0) return n/2;
    return grundy((n-1)/2);
}

int main(){
    int i,j,k,n,m,ts,cas=0,ans;
    cin>>ts;
    while(++cas<=ts){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            ans ^= grundy(m);
        }
        if(ans) printf("Case %d: Alice\n",cas);
        else printf("Case %d: Bob\n",cas);
    }
    return 0;
}
