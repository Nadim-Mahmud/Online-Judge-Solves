#include<iostream>
#include<cstdio>

using namespace std;

int pa[50];

int main(){

    int n,m,k,p,cas=0,t,x,y,i,j,ara[50][50],c,c1;

    cin>>t;
    while(++cas <= t){

        for(i=1;i<=49;i++) pa[i] = 0;
        cin>>n>>m>>k;
        for(i=1;i<=n;i++){
            for(j=1;j<=k;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        cin>>x;
        for(i=1;i<=x;i++){
            scanf("%d",&y);
            pa[y] = 1;
        }

        for(i=1;i<=n;i++){
            c = 0;
            for(j=1;j<=k;j++){
                x = ara[i][j];
                if(x>0 && (pa[x]==1)){
                    c=1;
                    //pa[x]++;

                    //cout<<"1 "<<x<<endl;
                }
                if(x<0&&pa[-1*x]==0){
                    c=1;
                    //cout<<x<<endl;
                }
            }
            if(!c) break;
            //cout<<c1<<endl;
        }

        cout<<"Case "<<cas<<": ";
        if(!c) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
