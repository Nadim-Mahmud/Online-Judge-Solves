#include<bits/stdc++.h>
#define ll long long
#define lt 100000

using namespace std;

ll ara[lt+5];

ll um(int n ){

    ll sum = 0,memo=ara[n];
    int i;

    for(i = (n-1) ; i > 0 ; i--){

        sum += abs(memo - (n-i)*ara[i]);
        memo += ara[i];
    }
    return sum;
}

int main(){

    int k,c,n,t,cas=0,i;

    cin>>t;

    while(++cas<=t){

        scanf("%d %d %d %d",&k,&c,&n,&ara[1]);

        for(i=2;i<=n;i++){
            ara[i] = (k*ara[i-1]+c)%1000007;
        }
        sort(ara+1,ara+n+1);
        //for(i=1;i<=n;i++)cout<<ara[i]<<endl;

    printf("Case %d: %lld\n",cas,um(n));
    }
    return 0;
}
