#include<bits/stdc++.h>
using namespace std;

char st[1000000];

int main(){

    int i,j,k;

    cin>>k>>st;

    for(i=1;st[i];i++){
        if(st[i]<st[i-1]){
            puts("YES");
            cout<<i<<" "<<i+1<<endl;
            return 0;
        }
    }
    puts("NO");

    return 0;
}
