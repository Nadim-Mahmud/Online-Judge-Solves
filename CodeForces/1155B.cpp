#include<bits/stdc++.h>
using namespace std;

char str[1000000];

int main(){

    int i,j,k,cn=0,c1,c2=0,n,x;

    cin>>n;
    cin>>str;

    k = strlen(str) - 11;
    x = k/2+1;

    i = 0;
    while(x&&str[i]){
        if(str[i]!='8') x--;
        else cn++;
        i++;
    }

    if(cn>k/2) puts("YES");
    else puts("NO");

    return 0;
}
