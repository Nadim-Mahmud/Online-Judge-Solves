#include<bits/stdc++.h>
#define ll long long
#define MX 20000000
using namespace std;

bool mark[20000000+5];
int v=0;
struct ab{int a,b;} st[1000000];

void sieve(void){
    int i,j,s = sqrt(MX)+1,a;
    a = 3;
    for(i=3;i<=MX;i+=2){
        if(!mark[i]){
            if((i-a)==2){
                st[++v].a = a;
                st[v].b = i;
            }
            if(i<=s){
                for(j=i*i;j<=MX;j+=(i<<1)){
                    mark[j] = 1;
                }
            }
            a=i;
        }
    }

}

int main(){

    int i,j,n,c,ans,x;
    sieve();
    //freopen("11466.txt","r",stdin);
    while(scanf("%d",&n)==1){
        printf("(%d, %d)\n",st[n].a,st[n].b);
    }
    return 0;
}

