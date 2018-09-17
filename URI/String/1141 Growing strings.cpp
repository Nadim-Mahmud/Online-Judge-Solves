#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char str[1001],str1[1001];

int main(){

    int a,b,i,j,c,c1,x,y,z,n,k;

    while(1){
        c1=0;
        c=0;
        z = 0;
        scanf("%d",&n);
        if(n == 0) break;
        c++;
        while(++z <= n){
            if(z == 1) scanf(" %[^\n]",str1);
            if(z>1){
                scanf(" %[^\n]",str);
                c1=0;
                for(i=0;str[i]!='\0';i++){
                    if(str[i] == str1[0]){
                        k = i-1;
                        for(j=0;str1[j] !='\0';j++){
                            if(str[++k] != str1[j]) break;
                            //cout<<j<<" "<<i<<endl;
                        }
                        if(str1[j] == '\0'){
                            c1++;
                            //cout<<c1<<" ccc "<<j<<endl;
                            break;
                        }
                    }
                }
                strcpy(str1,str);

                if(c1 == 0) c++;
               // cout<<" c :"<<c<<endl;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
