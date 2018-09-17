#include<iostream>

using namespace std;

int main(){

    int x,t,n,i,a[100],j;

    cin>>t;

    for(i=1;i<=t;i++){

        cin>>n;

        for(j=1;j<=n;j++){

            cin>>a[j];
        }

        x = (n+1)/2;
        cout<<"Case "<<i<<": "<<a[x]<<endl;
    }

    return 0;
}
