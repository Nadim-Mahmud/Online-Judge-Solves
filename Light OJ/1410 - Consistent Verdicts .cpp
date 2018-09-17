#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    int x,y;
}ara[705];
ll mp[705*705];

int main(){
    ll i,j,k,n,m,cas=0,ts,ans,cnt,v;
    cin>>ts;
    while(++cas<=ts){
        v = ans =0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld %lld",&ara[i].x,&ara[i].y);
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                mp[v++] = (ara[i].x-ara[j].x)*(ara[i].x-ara[j].x) + (ara[i].y-ara[j].y)*(ara[i].y-ara[j].y);
            }
        }
        sort(mp,mp+v);
        ans = v;
        for(i=0;i<v;i++){
            if(mp[i]==mp[i-1]) ans--;
        }
        printf("Case %lld: %lld\n",cas,ans+1);
    }
    return 0;
}
