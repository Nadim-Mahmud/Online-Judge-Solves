#include<bits/stdc++.h>

using namespace std;

char str[1000009];

int main(){

    int a,b,c=0,x,y,z,i;
    scanf("%s",str);
    stack<char> st;

    for(i=0;str[i] != '\0';i++){

        if(str[i] == '(') st.push('(');
        else{
            if(!st.empty()){
                st.pop();
                c +=2;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}

