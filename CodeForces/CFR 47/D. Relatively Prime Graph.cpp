#include<bits/stdc++.h>
using namespace std;

struct node{
    int a,b;
}ara[100005];

int main(){
    int n,m,in=0,i,j,cn=1;
    cin>>n>>m;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            if(in==m) break;
            if(__gcd(i,j)==1){
                ara[++in].a = i;
                ara[in].b = j;
                cn++;
            }
        }
        if(in==m) break;
    }
    if(in<m||cn<n) puts("Impossible");
    else{
        printf("Possible\n");
        for(i=1;i<=m;i++){
            printf("%d %d\n",ara[i].a,ara[i].b);
        }
    }
    return 0;
}
