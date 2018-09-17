#include<bits/stdc++.h>
#define p1(XX) cout<<"db1: "<<XX<<endl;
#define p2(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
using namespace std;

int mr[105],pr[100],v=0;
void seive(){
    int i,j;
    for(i=3;i<=100;i+=2){
        if(!mr[i]){
            for(j=i+i;j<=100;j+=i){
                mr[j]=1;
            }
        }
    }
    pr[++v] = 2;
    for(i=3;i<=100;i+=2){
        if(!mr[i]) pr[++v] = i;
    }
}

int ans[100000],ln;

void mult(int n){
    int tmp,cr=0,i;
    for(i=1;i<=ln;i++){
        tmp = ans[i]*n + cr;
        ans[i] = tmp%10;
        cr = tmp/10;
    }
    while(cr){
        ans[++ln] = cr%10;
        cr /= 10;
    }
}

int main()
{
    int i,j,k,n,m,ts,cas=0,cn=0,ara,ar[10005];
    //freopen("test.txt","r",stdin);
    seive();
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        ans[1]=ln=1;
        memset(ar,0,sizeof ar);
        //for(i=2;i<=10000;i++) if(ar[i]!=0)cout<<i<<endl;
        for(i=1;i<=n;i++){
            scanf("%d",&ara);
            for(j=1;pr[j]*pr[j]<=ara&&j<=25;j++){
                cn=0;
                while(ara%pr[j]==0){
                    cn++;
                    ara /= pr[j];
                }
                ar[pr[j]] = max(ar[pr[j]],cn);
            }
            if(ara>1) ar[ara] = max(ar[ara],1);
        }
//        p1("usdif\n")
//        for(i=2;i<=10000;i++) if(ar[i])cout<<i<<endl;
        for(i=2;i<=10000;i++){
            while(ar[i]>0){
               // p2(ar[i],i)
                mult(i);
                //for(int x=1;x<=5;x++) cout<<ans[x];
                ar[i]--;
            }
        }
        printf("Case %d: ",cas);
        for(i=ln;i>0;i--){
            if(i==1) printf("%d\n",ans[i]);
            else printf("%d",ans[i]);
        }
    }
    return 0;
}
