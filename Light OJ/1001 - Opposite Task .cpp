#include<iostream>

using namespace std;

int main(){

    int t,n,i;
    cin>>t;

    for(i=1;i<=t;i++){

        cin>>n;

        if( n<=10 ) cout<<"0 "<<n<<endl;
        else cout<<n/2<<" "<<n-n/2<<endl;

    }


    return 0;
}
