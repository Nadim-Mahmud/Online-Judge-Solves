#include<bits/stdc++.h>
using namespace std;

char str[500],ans[500];

int main()
{
    stack<char>st;
    int i,j,k,l,m,n,a,b,c,x,y,z,cas=0,ts,in=0;
    cin>>ts;
    while(++cas<=ts){
        scanf("%s",str);
        in = 0;
        for(i=0;str[i];i++){
            if(str[i]<='z'&&str[i]>='a'){
                ans[in++] = str[i];
            }
            else if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='^'||str[i]=='*'){
                st.push(str[i]);
            }
            else if(str[i]==')'){
                ans[in++] = st.top();
                   st.pop();
            }
        }
        ans[in] = '\0';
        printf("%s\n",ans);
    }
    return 0;
}
