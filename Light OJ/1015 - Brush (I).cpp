#include<iostream>

using namespace std;

int main(){

    int t,n,sum,a,i,j;
    cin>>t;

    for(i=1;i<=t;i++){

        cin>>n;

        sum = 0;

        for(j=1;j<=n;j++){

            cin>>a;

            if(a < 0) a =  0;

            sum += a;
        }

        cout<<"Case "<<i<<": "<<sum<<endl;
    }

    return 0;
}

