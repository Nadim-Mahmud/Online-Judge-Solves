#include<bits/stdc++.h>

using namespace std;
int ara[205][205],sum,x,n;

int main(){

    int cas=0,t,i,j,c;
    cin>>t;
    while(++cas<=t){
        scanf("%d",&n);
        sum = 0;
        c = n-1;
        x = 2*n-1;
        for(i=1;i<=x;i++){
            if(i<=n){
                for(j=1;j<=i;j++)
                    scanf("%d",&ara[i][j]);
            }
            else{
                for(j=1;j<=c;j++)
                    scanf("%d",&ara[i][j]);
                c--;
            }
        }
        c = 2;
        x--;
        for(i=x;i>0;i--){
            if(i<n){
                for(j=1;j<=i;j++){
                    ara[i][j] += max(ara[i+1][j],ara[i+1][j+1]);
                }
            }
            else{
                for(j=1;j<=c;j++){
                    if(j==1) ara[i][j] += ara[i+1][j];
                    else if(j==c){
                        ara[i][j] += ara[i+1][j-1];
                        //cout<<ara[i][j]<<i<<" "<<j<<endl;
                    }
                    else{
                        ara[i][j] += max(ara[i+1][j],ara[i+1][j-1]);
                        //cout<<ara[i][j]<<i<<" "<<j<<" "<<ara[i+1][j]<<" "<<ara[i+1][j+1]<<endl;
                    }
                    //cout<<"ss"<<ara[i][j]<<endl;
                }
                c++;
            }
        }
        printf("Case %d: %d\n",cas,ara[1][1]);

    }
    return 0;
}
