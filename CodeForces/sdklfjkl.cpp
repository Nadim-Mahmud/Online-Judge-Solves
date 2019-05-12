#include<bits/stdc++.h>
using namespace std;

int lcm(int a , int b){
    return (a*b)/__gcd(a,b);
}

int main(){
    int i,j,k,l,m,n,a,b,mn = 0;

    cin>>a>>b;

    for(i=0;i<=30;i++){
        m = __gcd(a+i,b+i);
        n = lcm(a+i,b+i);
        cout<<a+i<<" "<<b+i<<" "<<" "<<m<<" "<<n<<endl;
        mn = max(mn,m);
    }
    cout<<mn<<endl;
    return 0;
}
