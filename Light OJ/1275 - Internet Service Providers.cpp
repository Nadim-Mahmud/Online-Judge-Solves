#include<bits/stdc++.h>

using namespace std;

int main(){

    int cas=0,t,n,c,ans;

    cin>>t;
    while(++cas<=t){

        scanf("%d %d",&n,&c);

        if(n==0) ans = 0;
        else if(n>=c) ans=0;
        else{
            if(c%n==0) ans = (c/n)/2;
            else ans = ((c/n)+1)/2;
        }

        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
