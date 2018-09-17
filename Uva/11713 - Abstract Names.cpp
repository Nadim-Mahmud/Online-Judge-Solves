#include<bits/stdc++.h>

using namespace std;

int main(){

    int a,b,c=0,c1,i,j,t,cas=0;
    char str[25],str1[25];

    cin>>t;
    getchar();
    while(++cas <= t){

        c1 = 0, c = 0;

        gets(str);
        gets(str1);
        //scanf("%s",str);
        //scanf("%s",str1);

        for(i=0;str[i] != '\0';i++){
            c1++;
            if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
                if(str[i] != str1[i]){
                    c = - 1;
                };
            }
        }

        if(c1 == strlen(str1) && c == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
