#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
}ab;

int ara[105],n;
vector<edge>vc;
map<string,int>mp;

bool cmp(edge st,edge st1){
    if(st.w<st1.w) return true;
    else return false;
}

int rec(int n){
    if(ara[n] == n) return n;
    return ara[n] = rec(ara[n]);
}

int mst(){
    int sum=0,i,u,v,cn=0;
    for(i=0;i<=102;i++) ara[i] = i;
    for(i=0;i<(int)vc.size();i++){
        u = rec(vc[i].u);
        v = rec(vc[i].v);
        if(u!=v){
            ara[v] = u;
            sum+=vc[i].w;
            cn++;
            if(cn==n) break;
        }
    }
    return sum;
}

int main(){
    int i,j,k,a,b,ts,cas=0,v,cn=0;
    string st,str;
   // freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        v=0;
        cn=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            cin>>str>>st;
            cin>>ab.w;
//            a = mp.find(str);
//            b = mp.find(st);
            //cout<<str<<" "<<st<<endl;
            if(mp.find(str)==mp.end()) mp[str] = ++v;
            if(mp.find(st)==mp.end()) mp[st] = ++v;
            ab.u = mp[str];
            ab.v = mp[st];
            //cout<<ab.u<<" "<<ab.v<<" "<<v<<endl;
            vc.push_back(ab);
        }
//        for(i=0;i<vc.size();i++){
//            cout<<vc[i].u<<" "<<vc[i].v<<" "<<vc[i].w<<endl;
//        }
        sort(vc.begin(),vc.end(),cmp);
        a = mst();
        b = rec(1);
        for(i=1;i<=v;i++){
            if(b!=rec(i)) cn = 1;
        }

        if(cn) printf("Case %d: Impossible\n",cas);
        else printf("Case %d: %d\n",cas,a);
        vc.clear();
        mp.clear();
    }
    return 0;
}

