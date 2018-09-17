#include<bits/stdc++.h>

using namespace std;

int ara[150];
char str[1005];

void replace(){
    int i,j,x;
    for(i=0;str[i];i++){
        x = str[i];
        if(ara[x] != 0) str[i] = str[0];
        else ara[x] ++;
    }
}

int main(){

    int i,s,c=0,t,cas=0,j,x;
    char tmp;

    cin>>t;
    getchar();

    while(++cas <= t){

        memset(ara,0,sizeof(ara));

        gets(str);

        for(i=0;str[i] != '\0'; i++){
            for(j=i;str[j] != '\0'; j++){
                if(str[i] > str[j]){
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
            if(i==0) replace();
        }
        printf("%s\n",str);
    }
    return 0;
}
