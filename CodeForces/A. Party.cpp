#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int n,i,j,c=0,ara[20000];

    cin>>n;

    for(i=1;i<=n;i++){
        scanf("%d",&ara[i]);
    }

    for(i=1;i<=n;i++){
        if(ara[i] > 0||ara[i] < 0){
            c++;
            for(j=i+1;j<=n;j++){
                if(ara[i] == ara[j]){
                    ara[j] = 0;
                }
            }
        }
    }
    cout<<c<<endl;;


    return 0;
}
