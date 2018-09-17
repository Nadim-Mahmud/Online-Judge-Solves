#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){

    int c,x,a,c1,i,c3;
    char str[105];

    while(1){
        c = 0;
        c1 = 0;
        c3 = 0;
        scanf("%d",&x);
        scanf("%s",str);

        if(x == 0 && str[i] == 0) break;

        for(i=0;str[i] != '\0';i++){
            if(str[i] != x+48){
                if(str[i] != '0') c1++;
                //cout<<"y: "<<c1<<endl;
                c++;
                if(c1 > 0) c = 0;
                if(c == 0){
                    printf("%c",str[i]);
                    c3++;
                }
            }
        }
        if(c3==0) cout<<0;
        printf("\n");
    }
    return 0;
}
