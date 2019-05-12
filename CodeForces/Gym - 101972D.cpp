#include<bits/stdc++.h>
using namespace std;

int main(){

    int i,j,ts,n,x,y,a;

    cin>>ts;
    while(ts--){
        cin>>n>>x>>y;
        a = n/2;
        if(x>=a+1&&a<=y){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
