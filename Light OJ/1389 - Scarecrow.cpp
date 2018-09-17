#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int cas=0,t,i,c=0,n,x;
    char ch;

    scanf("%d",&t);
    while(++cas<=t){
        c = 0;
        x = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            //cout<<i<<endl;
            scanf(" %c",&ch);
            //cout<<i<<x<<endl;
            if(ch == '.' && x < i){
                c++;
                x = i + 2;
            }
        }
        printf("Case %d: %d\n",cas,c);
    }
    return 0;
}
