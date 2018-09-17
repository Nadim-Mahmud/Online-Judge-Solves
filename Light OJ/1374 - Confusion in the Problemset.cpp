#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int ara[10005];

int main(){

    int n,i,p,cas=0,t;
    cin>>t;
    while(++cas<=t){
        scanf("%d", &n);

        for(i=0;i<=n;i++) ara[i]=0;

        for(i=0;i<n;i++){

            scanf("%d", &p);
            if(p>=0 && p<=n) ara[p]++;
        }

        int cnt = 0;

        for(i=0;i<n;i++){

            if(ara[i]>0){
                cnt++;
                ara[i]--;
            }
            else if(ara[n-i-1]>0){
                cnt++;
                ara[n-i-1]--;
            }
        }
        if(cnt>=n) printf("Case %d: yes\n", cas);
        else printf("Case %d: no\n", cas);
    }
    return 0;
}

/*
int ara[10009];

int main(){

    int cas=0,t,i,j,n,c,x,y,c1;
    cin>>t;
    while(++cas<=t){
        c = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        sort(ara+1,ara+n+1);
        x = n;
        //for(i=1;i<=n;i++) cout<<ara[i];
        //cout<<endl;
        for(i=n,c1=n-1;i>0;i--,c1--){
            if(ara[i] != c1){
                if(ara[i] == (x-1)){
                    x--;
                    c1++;
                }
                else{
                    c++;
                    //cout<<i<<ara[i]<<endl;
                }
            }
        }
        if(c != 0) printf("Case %d: no\n",cas);
        else printf("Case %d: yes\n",cas);
    }
    return 0;
}*/

