#include<bits/stdc++.h>
#define MX 100000000
using namespace std;

char stt[5],tt[5],fi[30],se[30],th[30],cn;

int dist(char *st,int x){
    int i,j,k,a,b;
    char s,t;
    s = stt[x];
    t = tt[x];
    if(s>t) swap(s,t);
    //cout<<s<<t<<endl;
    a = (t - s);
    b = (s - 'a') + ('z' - t) + 1;
    if(cn==-1) return min(a,b);
   // cout<<a<<" "<<b<<endl;
    for(i=0;st[i];i++){
        if(s<=st[i]&&t>=st[i]){
            a = MX;
            break;
        }
    }
    for(i=0;st[i];i++){
        if(s>=st[i]||t<=st[i]){
            b = MX;
            break;
        }
    }
    return min(a,b);
}

int solve(char *fi,char *se,char *th){
    int i,tmp,ans=MX;
    cn=0;
    tmp = dist(fi,0);
    cn = -1;
    tmp += dist(se,1) + dist(th,2);
    ans = min(ans,tmp);
    cn = 0;
    tmp = dist(se,1);
    cn=-1;
    tmp += dist(fi,0) + dist(th,2);
    //cout<<tmp<<endl;
    ans = min(ans,tmp);
    cn=0;
    tmp = dist(th,2);
    cn=-1;
    tmp += dist(fi,0) + dist(se,1);
    return min(ans,tmp);
}

int main(){
    int i,j,k,l,m,n,cas=0,ts,ans,tmp,mr=0;
    freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%s %s %d",stt,tt,&m);
        ans=MX;
        mr=0;
        for(k=1;k<=m;k++){
            scanf("%s %s %s",fi,se,th);
            ans = min(solve(fi,se,th),ans);
            mr=1;
        }
        if(ans==MX&&mr==0) ans=0;
        if(ans>=MX) printf("Case %d: %d\n",cas,-1);
        else printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
