#include<bits/stdc++.h>
#define ll long long
using namespace std;

char st[1000][1000];

int main(){
    int i,j,k,x,y,cn=0,n=0,m=0;
    cin>>x>>y;
    for(i=0;i<x;i++){
        cin>>st[i];
    }
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            if('B'==st[i][j]){
                if(!cn) n = i,m = j;
                cn++;
            }
        }
        if(cn) break;
    }
    cout<<(n+cn/2+1)<<" "<<(m+cn/2+1)<<endl;
    return 0;
}
