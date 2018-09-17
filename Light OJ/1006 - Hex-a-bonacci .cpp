#include<iostream>
#include<cstdio>

using namespace std;
int main(){

    int ara[10009],cas=0,t,i,n;
    cin>>t;
    while(++cas <= t){

        scanf("%d %d %d %d %d %d %d",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4],&ara[5],&n);
        for(i=6;i<=n;i++){
            ara[i] = (ara[i-1]%10000007 + ara[i-2]%10000007 + ara[i-3]%10000007 + ara[i-4]%10000007 + ara[i-5]%10000007 + ara[i-6]%10000007)%10000007;
        }
        printf("Case %d: %d\n",cas,ara[n]%10000007);
    }
    return 0;
}
