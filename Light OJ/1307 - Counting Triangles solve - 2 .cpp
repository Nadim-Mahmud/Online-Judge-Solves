

///TLE mathod :)


#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int ara[2005],n,j;

int main(){

    int cas=0,t,i,a,c=0,x;
    scanf("%d",&t);
    while(++cas<=t){
        c = 0;
        a = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        sort(ara+1,ara+n+1);

        for(i=1;i<=(n-2);i++){
            for(j=i+1;j<=(n-1);j++){
                x = ara[i] + ara[j];
                a = j+1;
                //cout<<x<<" "<<ara[a]<<endl;
                while(ara[a]<x && a != n){
                    c++;
                    a++;
                    //cout<<a<<endl;
                }
                if(a == n && ara[n] < x) c++;
            }
        }
        printf("Case %d: %d\n",cas,c);
    }
    return 0;
}

