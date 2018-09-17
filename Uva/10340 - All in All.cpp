#include<bits/stdc++.h>

using namespace std;

char str[10000000];

int main(){

    int i,j,k,c,v,c1,c2;

    while(gets(str)){

        v = 0,c1=0,c2=0,c=0;
        for(i = 0 ; str[i] != '\0'; i++){
            if(str[i] == ' '){
                i++;
                while(str[i]){
                    if(str[i] == str[v] ){
                        //cout<<str[i]<<" "<<str[v]<<endl;
                        v++;
                        c2++;
                    }
                    i++,c++;
                }
                break;
            }
            else c1++;
        }

        //cout<<c1<<" "<<c<<" "<<c2<<endl;
        if(c1==c2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
