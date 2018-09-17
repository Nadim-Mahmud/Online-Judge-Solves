#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("t","w",stdout);
#define pii pair<string,string>
using namespace std;

map<pii,bool>mp;

int main()
{
    int i,j,a,b,ts,cn=0,n,c;
    //freopen("test.txt","r",stdin);
    string s1,s2;
    scanf("%d",&ts);
    while(++cn<=ts){
        c = 0;
        mp.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            cin>>s1>>s2;
            mp[pii(s2,s1)] = 1;
            if(mp[pii(s1,s2)] == 1) c = 1;
        }

        if(!c) printf("Case %d: Yes\n",cn);
        else printf("Case %d: No\n",cn);
    }
    return 0;
}

