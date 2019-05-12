#include <bits/stdc++.h>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"d2 "<<X<<" "<<Y<<endl;
#define P3(X,Y,Z) cout<<"d3 "<<X<<" "<<Y<<" "<<Z<<endl;
#define ll long long
#define rep(i,n) for(i=1;i<=n;i++)
#define FO freopen("out.txt","w",stdout);
#define FIN freopen("inp.txt","r",stdin);
#define MS(XX,YY) memset(XX,YY,sizeof(XX));
#define pii pair<int,int>
using namespace std;
const int N=10004669;
bool mark[N+5];
int primes[1000005], np;
void sieve()
{
    np=1;
    int sq=sqrt(N)+2;
    primes[np++]=2;
    for(int i=3;i<=sq; i+=2){
        if(!mark[i])
        {
            for(int j=i*i;j<=N; j+=i)mark[j]=true;
        }
    }
    for(int j=3;j<=N; j+=2)if(!mark[j])primes[np++]=j;
    ///cout<<np<<endl<<primes[np-1];
}


int main()
{
    //FIN
    sieve();
    while(1)
    {
        int n, nf=0, m;
        scanf("%d", &n);
        m=n;
        if(n==0)break;
        printf("%d =", n);
        for(int i=1; primes[i]*primes[i]<=n&&i<np; i++){
            while(n%primes[i]==0 ){
                if(n==1)break;
                if(n==0){
                    //cout<<"Oreee bal-"<<endl;
                    break;
                }
                n/=primes[i];
                nf++;
                if(nf==1){
                    printf(" %d", primes[i]);
                }
                else printf(" * %d", primes[i]);
            }
        }
        if(n>1){
            nf++;
            if(nf==1){
                printf(" %d",n);
            }
            else printf(" * %d",n);
        }

        printf("\nWith %d marbles, %d different rectangles can be constructed.\n", m, nf);
    }
    return 0;
}



