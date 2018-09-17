#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int ara[1000];

int main(){

    int t,i,n,m,d,a,b,x,k,j,l;
    //double d;
    char ch;

    cin>>t;

    for(k=1;k<=t;k++){

        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++){
            scanf("%d",&ara[i]);
        }
        //cout<<"y"<<endl;

        for(l=1;l<=m;l++){

            scanf(" %c",&ch);

            if(ch == 'S'){

                scanf("%d",&d);
                for(j=0;j<n;j++){

                    ara[j] += d;
                }
            }
            else if(ch == 'M'){

                scanf("%d",&d);
                for(j=0;j<n;j++){

                    ara[j] = ara[j]*d;
                }
            }
            else if(ch == 'D'){

                scanf("%d",&d);
                for(j=0;j<n;j++){

                    ara[j] = ara[j]/d;
                }
            }
            else if(ch == 'R'){

                reverse(ara,ara+n);
            }
            else if(ch == 'P'){

                scanf("%d %d",&a,&b);

                x = ara[a];
                ara[a] = ara[b];
                ara[b] = x;
            }
        }

        printf("Case %d:\n",k);

        for(i=0;i<n;i++){

            if(i == (n-1)) printf("%d\n",ara[i]);
            else printf("%d ",ara[i]);
        }
    }
    return 0;
}
