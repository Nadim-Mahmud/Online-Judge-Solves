#include<bits/stdc++.h>

using namespace std;

int ara1[100],ara2[100];

int main(){

    int cas=0,t,i,a,b,n,x,c=0,ans=0,c1,c2,j;
    ///freopen("1198.txt","r",stdin);
    cin>>t;
    while(++cas<=t){
        scanf("%d",&n);
        c = 0;
        for(i=1;i<=n;i++) scanf("%d",&ara1[i]);
        for(i=1;i<=n;i++) scanf("%d",&ara2[i]);

        sort(ara1+1,ara1+n+1);
        sort(ara2+1,ara2+n+1);

        for(i=1;i<=n;i++){
            for(j=n;j>0;j--){
                if(ara1[i] > ara2[j] && ara1[i] != 0 && ara2[j] != 0){
                    //cout<<ara1[i]<<" :: "<<ara2[j]<<endl;
                    ara1[i] = 0;
                    ara2[j] = 0;
                    c+=2;
                    break;
                }
            }
        }
        //cout<<c<<endl;
        for(i=1;i<=n;i++){
            for(j=n;j>0;j--){
                //cout<<ara1[i]<<" jjjjj "<<ara2[j]<<endl;
                if(ara1[i] == ara2[j] && ara1[i] != 0&& ara2[j] != 0){
                    ara1[i] = 0;
                    ara2[j] = 0;
                    c++;
                    break;
                }
            }
        }

        printf("Case %d: %d\n",cas,c);
    }
    return 0;
}
