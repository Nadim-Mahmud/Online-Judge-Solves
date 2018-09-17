#include<bits/stdc++.h>

using namespace std;

char str[10000000];

int main(){

    int x,y,c,i;

    while(gets(str)){

        for(i=0;str[i] != '\0';i++){

            x = str[i];
            //if(x < 9) x = 48 + str[i];
            //cout<<"    "<<x<<endl;
            str[i] = x - 7;

        }
        printf("%s\n",str);
    }
    return 0;
}
