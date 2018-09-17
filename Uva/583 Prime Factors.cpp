#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int ara[mx+5][2],pr[mx+5],k=0;

void sieve(){

    int i,j,r=sqrt(mx);

    pr[++k] = 2;

    for(i = 3;i <= mx;i += 2){
        if(pr[i]==0){
            pr[++k] = i;
            if(i<=r){
                for(j=i*i ; j <= mx ; j += i+i){
                    pr[j] = 1;
                }
            }
        }
    }
}

int main(){

    int n,i,c,s,mem,v=0;
    sieve();

    while(1){

        scanf("%d",&n);
        if(n == 0) break;
        mem = n;
        c = 0,s = 0,v = 0;
        if(n<0) s++,n = -1*n;

        for(i=1; i<=k && pr[i]*pr[i] <= n ; i++){

            if(n%pr[i] == 0) ara[++v][0] = pr[i];

            while(n%pr[i] == 0){
                n /= pr[i];
                ara[v][1]++;
                //cout<<ara[v][1];
            }
        }

        int c1=0;

        printf("%d = ",mem);
        if(s!=0) c1++,printf("-1");

        if(ara[1][0] != 0){
                if(c1>0) printf(" x %d",ara[1][0]);
                else c1++, printf("%d",ara[1][0]);
                --ara[1][1];
        }

        for(i=1;i<=v;i++){
            while(ara[i][1]--){
                printf(" x %d",ara[i][0]);
            }
            ara[i][0] = 0;
            ara[i][1] = 0;
        }

        if(n>1){
            if(c1>0) printf(" x %d",n);
            else printf("%d",n);
        }

        printf("\n");
    }
    return 0;
}
