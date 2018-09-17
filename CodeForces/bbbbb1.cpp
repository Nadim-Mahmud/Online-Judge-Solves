#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll x,y;
}ara[1000000];

ll dv[10],in=0,tin=0,tmp[10];

void keep(int i){
    int j;
    if(i==1){
        for(j=1;j<=tin;j++){
            dv[++in] = tmp[i];
        }
        tin=0;
        return;
    }
    for(i=1;i<=in;i++){
        int cn=0;
        for(j=1;j<=tin;j++){
            if(tmp[j]==dv[i]) cn=1;
        }
        if(cn==0) dv[i] = -1;
    }
    tin = 0;
}

int main(){
    ll i,j,k,l,n=1000,m,cn=0;

    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&ara[i].x,&ara[i].y);
    }
    for(i=1;i<n;i++){
        m = __gcd(ara[i].x,ara[i+1].x);
        if(m!=1) tmp[++tin] = m;
        m = __gcd(ara[i].x,ara[i+1].y);
        if(m!=1) tmp[++tin] = m;
        m = __gcd(ara[i].y,ara[i+1].x);
        if(m!=1) tmp[++tin] = m;
        m = __gcd(ara[i].y,ara[i+1].y);
        if(m!=1) tmp[++tin] = m;
        for(j=1;j<=tin;j++) cout<<tmp[j]<<" ";
        cout<<endl;
        keep(i);
    }
    for(i=1;i<=in;i++){
        if(dv[i]!=-1){
            cout<<dv[i]<<endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}
