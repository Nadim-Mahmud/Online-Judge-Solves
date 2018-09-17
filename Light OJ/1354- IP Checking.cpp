#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[10000];

long long bin(long long m=16){

    long long x = 0,i,n,c=0;

    for(i=1;m != 0;i++){

        a[i] = m%2;
        m = m/2;
        c++;
    }

    reverse(a+1,a+c+1);

    for(i=1;i<=c;i++){

        x = x*10;
        x += a[i];
    }

    return x;
}

int main(){

    long long n,t,i,j,k,nstr1,nstr2,a,b,c,d,x,y,z,w;

    char str1[1000],str2[1000],r;

    //freopen("1354.txt","r",stdin);

    cin>>t;

    for(k=1;k<=t;k++){

        scanf("%s",str1);
        scanf("%s",str2);
        sscanf(str1,"%lld%c%lld%c%lld%c%lld",&a,&r,&b,&r,&c,&r,&d);
        sscanf(str2,"%lld%c%lld%c%lld%c%lld",&x,&r,&y,&r,&z,&r,&w);

        if(x == bin(a) && y == bin(b) && z == bin(c) && w == bin(d)) printf("Case %lld: Yes\n",k);
        else printf("Case %lld: No\n",k);
    }


    return 0;
}

