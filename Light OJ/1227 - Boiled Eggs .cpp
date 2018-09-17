#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int i,j,t,n=0,p=0,q=0,a[100],c = 0,sum;

    cin>>t;

    for(j=1;j<=t;j++){

        scanf("%d %d %d",&n,&p,&q);

        //cout<<n<<p<<q<<endl;

        for(i=1;i<=n;i++){

            scanf("%d",&a[i]);
        }

        sum  = 0;
        c = 0;

        for(i=1;i<=n;i++){

            sum += a[i];

            if(sum <= q && i<=p) c++;
            else break ;
        }

        printf("Case %d: %d\n",j,c);
    }

    return 0;
}
