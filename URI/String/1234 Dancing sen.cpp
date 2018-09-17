#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){

    int i,c=0,c1,j;
    char str[100];

    while(gets(str)){
        c = 0;
        for(i=0;str[i] != '\0';i++){
            if(str[i] != ' '){
                c++;
                if(c%2==0){
                    if(str[i]>='A'&&str[i]<='Z') str[i] += 32;
                }
                else{
                    if(str[i]>='a'&&str[i]<='z') str[i] -= 32;
                }
            }
        }
        //cout<<"y";
        //cout<<str[0];
        //for(i=0;str[i] != '\0';i++) printf("%c",str[i]);
        printf("%s\n",str);
    }
    return 0;
}
