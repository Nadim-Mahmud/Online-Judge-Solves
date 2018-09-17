#include<iostream>
#include<cstdio>

using namespace std;


int main(){

    int cas=0,t,i,c,sum;
    char str[105];
    cin>>t;
    while(++cas<=t){
        scanf("%s",&str);
        c = 0;
        sum = 0;
        for(i=0;str[i] != '\0';i++){
            if(str[i] == '1') sum+=2;
            else if(str[i]=='2'||str[i]=='3'||str[i]=='5') sum += 5;
            else if(str[i]=='4') sum +=4;
            else if(str[i]=='6'||str[i]=='0'||str[i]=='9') sum += 6;
            else if(str[i]=='7') sum += 3;
            else if(str[i]=='8') sum += 7;
        }
        printf("%d leds\n",sum);
    }
    return 0;
}
