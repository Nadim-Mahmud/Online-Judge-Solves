#include<bits/stdc++.h>

using namespace std;

int main(){

    int a,k,i,ans,cas=0,t;

    cin>>t;
    while(++cas<=t){

        scanf("%d %d",&a,&k);
        ans = 1;
        for(i=2;i<=a;i++){
            ans += k;
            if(ans%i == 0) ans = i;
            else if(ans>i) ans = ans%i;
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
