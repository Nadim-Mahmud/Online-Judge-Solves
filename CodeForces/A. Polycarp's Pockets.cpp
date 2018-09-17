#include<bits/stdc++.h>
using namespace std;

int ara[105];

int main(){
    int i,j,k,cnt=0,n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>k;
        ara[k]++;
        cnt = max(cnt,ara[k]);
    }
    cout<<cnt<<endl;
    return 0;
}
