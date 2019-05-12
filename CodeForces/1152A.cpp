#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,x,y,o1=0,o2=0,e1=0,e2=0;

    cin>>n>>m;

    for(i=1;i<=n;i++){
        cin>>x;
        if(x%2) o1++;
        else e1++;
    }
    for(i=1;i<=m;i++){
        cin>>x;
        if(x%2) o2++;
        else e2++;
    }
    cout<<min(o1,e2)+min(o2,e1)<<endl;

    return 0;
}
