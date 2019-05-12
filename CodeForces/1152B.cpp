#include<bits/stdc++.h>
using namespace std;

bool check(unsigned int n){
    if( __builtin_popcount(n+1)==1) return 1;
    return 0;
}

int pos(int n){
    int i = 0,rt=0;
    while(n){
        if(!(n&1)) rt = i;
        i++;
        n /= 2;
    }
    return rt+1;
}

int ans[1000000];

int main(){
    unsigned int n,cn=0,x,xr,in=0,i;
//    cout<<(1<<4)<<endl;
    cin>>n;

    while(!check(n)){
        cn++;
        x = pos(n);
        xr = (1<<x) - 1;
        ans[++in] = x;
        n ^= xr;
        if(check(n)) break;
        n += 1;
        cn++;
        //cout<<n<<endl;
    }
    cout<<cn<<endl;
    if(in){
        for(i=1;i<=in;i++){
            if(i==in) cout<<ans[i]<<endl;
            else cout<<ans[i]<<" ";
        }
    }
    return 0;
}

