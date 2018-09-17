#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char ara[5000],a[5000],b[5000];

void mul(){
    int c1=-1,i,j,k=-1,x,c=0,l,m;
    memset(ara,0,5000);
    m = strlen(a);
    l =  strlen(b);
    for(i=l-1;i>=0;i--){
        k = c1;
        c1++;
        for(j=m-1;j>=0;j--){
            x = (b[i]-48)*(a[j]-48) + c;
            c = 0;
            if(i==l-1){
                ara[++k] = x%10;
                c = x/10;
                }
            else{
                ara[++k] += x%10;
                c = x/10;
            }
            if(a[j+1] == '\0' && c>0) ara[++k] = c;
        }
    }
    reverse(ara,ara+k+1);
}



int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){

    int t,cas=0,i,j,n,c,x;
    //char a[5000],b[5000];

    scanf("%d",&t);
    while(++cas <= t){

        scanf("%lld",&n);
        n--;
        for(i=1;i<=n;i++){
            if(i==1) scanf("%s",b);
            scanf("%s",&a);
            c = b%a;
            b = (a/gcd(a,b))*b;
        }
        //printf("Case %lld: %lld\n",cas,b);
    }
    return 0;
}
