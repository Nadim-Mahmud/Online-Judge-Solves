#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,n,m,x,y,cas=0,ts,ans,x1,x2,x3,cn=0,tmp;
    char str[13];
    scanf("%d",&ts);
    while(++cas<=ts){
        scanf("%d %d",&n,&m);
        tmp = ans=cn=x1=x2=x3=0;
        for(i=1;i<=n;i++){
            scanf("%s",&str);
            x = 0;
            for(j=2;str[j];j++){
                x = x*10 + str[j] - '0';
            }
            if(str[0]=='B'){
                if(cn>1) ans = max(ans,tmp);
                ans = max(x-x1,ans);
                x3 = x2 = x1 = x;
                cn=0;
            }
            else{
                tmp = max(x-x1,tmp);
                x1 = x2;
                x2 = x;
                cn++;
            }
        }
        if(cn>1) ans = max(ans,tmp);
        printf("Case %d: %d\n",cas,max(ans,m-x1));
    }
    return 0;
}
