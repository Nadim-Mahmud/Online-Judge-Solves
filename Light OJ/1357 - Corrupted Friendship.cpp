#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,pr;
vector<int>ed[100005];

void dfs(int x){
    int i,v;
    pr++;
    for(i=0;i<ed[x].size();i++){
        v = ed[x][i];
        dfs(v);
    }
    //cout<<pr<<endl;
    ans += n - pr;
    //cout<<" n "<<n<<endl;;
}


int main()
{
    int ts,cas=0,i,j,x,y;
    cin>>ts;
    while(++cas<=ts){
        for(i=0;i<=100000;i++){
            ed[i].clear();
        }
        scanf("%lld",&n);
        for(i=1;i<n;i++){
            scanf("%d %d",&x,&y);
            ed[x].push_back(y);
        }
        ans=0,pr=0;
        dfs(1);
        printf("Case %d: %lld %lld\n",cas,n-1,ans);
    }
    return 0;
}
