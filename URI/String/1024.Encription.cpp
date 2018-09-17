#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){

    int cas = 0,t,i,c,x,y;
    char str[1009];

    cin>>t;
    while(++cas<=t){

        scanf(" %[^\n]",str);

        x = strlen(str);
        if(x%2 == 0) y = x/2 - 1;
        else y = x/2;
        ///cout<<y;

        for(i= 0;i < x;i++){
            if(i <= y){
                if((str[i]>='A' && str[i] <= 'Z')||(str[i] >= 'a'&&str[i]<= 'z')){
                        str[i] += 2;
                        ///cout<<"yes"<<endl;
                }
                else str[i] -= 1;
            }
            else{
                if((str[i]>='A' && str[i] <= 'Z')||(str[i] >= 'a'&&str[i]<= 'z')) str[i] += 3;
            }
        }
        reverse(str,str+x);
        printf("%s\n",str);
    }

    return 0;
}
