#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
}ab;

int ara[105],n;
vector<edge>vc;

bool cmp(edge st,edge st1){
    if(st.w<st1.w) return true;
    else return false;
}

int find(int n){
    if(ara[n] == n) return n;
    return ara[n] = find(ara[n]);
}

int mst(){
    int sum=0,i,u,v,cn=0;
    for(i=0;i<=102;i++) ara[i] = i;
    for(i=0;i<(int)vc.size();i++){
        u = find(vc[i].u);
        v = find(vc[i].v);
       // cout<<vc[i].w<<" "<<vc[i].u<<" "<<vc[i].v<<" "<<u<<" "<<v<<endl;
        if(u!=v){
            ara[v] = u;
            sum+=vc[i].w;
            //cout<<sum<<endl;
            cn++;
            //cout<<cn<<" "<<n<<endl;
            if(cn==n) break;
        }
    }
    return sum;
}

int main(){
    int i,j,k,a,b,ts,cas=0;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        for(;;){
            scanf("%d %d %d",&ab.u,&ab.v,&ab.w);
            if(ab.u==0&&ab.v==0&&ab.w==0) break;
            vc.push_back(ab);
        }
        sort(vc.begin(),vc.end(),cmp);
        a = mst();
        reverse(vc.begin(),vc.end());
        b = mst();
        //cout<<a<<" "<<b<<endl;
        if((b+a)%2==0) printf("Case %d: %d\n",cas,(b+a)/2);
        else printf("Case %d: %d/%d\n",cas,(a+b),2);
        vc.clear();
    }
    return 0;
}
