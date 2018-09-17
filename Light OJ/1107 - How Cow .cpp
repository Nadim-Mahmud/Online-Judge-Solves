#include<iostream>

using namespace std;

int main(){

    int x,y,a,b,m,n,t1,t2,i,j;

    cin>>t1;

    for(i=1;i<=t1;i++){

        cin>>a>>b>>x>>y>>t2;
        cout<<"Case "<<i<<":\n";

        for(j=1;j<=t2;j++){

            cin>>m>>n;

            if((m > a && m < x) && ( n > b && n < y)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }

    return 0;
}
