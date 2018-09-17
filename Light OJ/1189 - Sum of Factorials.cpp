#include<iostream>
#include<cstdio>

using namespace std;

long long arr[25],out[25];

void free(){
    for(int i = 0;i<=24;i++) out[i] = 0;
}

void fact(){
    long long i,x=1;
    arr[0] = 1;
    for(i=1;i<=20;i++){
        x *= i;
        arr[i] = x;
    }
}

int main(){

    long long n,valu,t,cas = 0,i,c,x;
    cin>>t;
    fact();
    while(++cas<=t){
        scanf("%lld",&x);
        c = 0;
        free();
        n = x;
        for(i=20;i>=0;i--){
            if(x >= arr[i]){
                if((n - arr[i]) < 0) continue;
                n = n - arr[i];
                //cout<<n<<" "<<i<<endl;
                out[i] = 1;
                //cout<<n<<" "<<i<<" "<<out[i]<<endl;
                if( n == 0) break;
            }
        }

        printf("Case %lld: ",cas);
        if(n == 0){
            for(i=0;i<=24;i++){
                if(out[i] != 0){
                    c++;
                    if(c == 1 )printf("%lld!",i);
                    else printf("+%lld!",i);
                }
            }
            printf("\n");
        }
        else printf("impossible\n");
    }
    return 0;
}
