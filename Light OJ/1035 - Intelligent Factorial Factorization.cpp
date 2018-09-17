#include<iostream>
#include<cstdio>
#include<cmath>
#define eps 10e-6

int s[105];
using namespace std;

int main(){

    int n,cas=0,t,i,a,j,k,c,x;
    cin>>t;
    while(++cas<=t){

        for(i=0;i<=100;i++){
            s[i] = 0;
        }
        scanf("%d",&n);
        x=n;
        c =0;

       for(x=2;x<=n;x++){
            a = x;
            while(a%2==0){
                s[2]++;
                a = a/2;
            }

            k = sqrt(a) + eps;
            for(i=3;i<=k;i+=2){
                while(a%i==0){
                    s[i]++;
                    a = a/i;
                }
            }
            if(a>2) s[a]++;
        }
        printf("Case %d: %d = ",cas,n);
        for(i=0;i<105;i++){
            if(s[i]>0){
                c++;
                if(c==1) printf("%d (%d)",i,s[i]);
                else printf(" * %d (%d)",i,s[i]);
            }
        }
        printf("\n");

    }
    return 0;
}
