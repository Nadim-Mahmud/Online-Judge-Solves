#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
using namespace std;
#define MX 1000002
#define gama .57721566490153286060651209

double ara[MX+5],v=0;

void sum()
{
    double sm=0;
    int i,j=1,k;
    for(i=1;i<=MX;i++){
        k = i*100;
        for(j;j<=k;j++){
            sm += 1.0/(double)j;
            //v++;
        }
        ara[i] = sm;
    }
    //cout<<v<<endl;
}

int main()
{
    int i,j,a,b,ts,cas=0,n;
    double ans;
    sum();
    scanf("%d",&ts);
    while(++cas<=ts){
        scanf("%d",&n);
        a = n/100;
        ans = ara[a];
        for(i=(a*100)+1;i<=n;i++){
            ans += 1.0/(double)i;
        }
        printf("Case %d: %.10lf\n",cas,ans);
    }
    return 0;
}
