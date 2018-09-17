#include<bits/stdc++.h>

using namespace std;

int ara[5005];

int main(){

    int i,j,n,cas=0,t,c;
    cin>>t;
    while(++cas <= t){

        scanf("%d",&n);
        c = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
            j = i-1;
            while(j>0){
                if(ara[i] >= ara[j]) c++;
               //1 cout<<i<<" "<<ara[j]<<" "<<c<<endl;
                j--;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
