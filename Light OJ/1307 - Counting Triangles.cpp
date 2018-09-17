#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int ara[2005],n,j;

int bisec(int x){
    int l = j,h = n,m;
    while(h-l>5){
        m = (l+h)/2;

        if(x<ara[m]) h = m;
        else l = m;
    }
    for(l;l<=h;l++){
        if(x<=ara[l]){
            l--;
            break;
        }
        if(l == h) break;
    }
    return l;
}

int main(){

    int cas=0,t,i,a,c=0,x;
    scanf("%d",&t);
    while(++cas<=t){
        c = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        sort(ara+1,ara+n+1);

        for(i=1;i<=(n-2);i++){
            for(j=i+1;j<=(n-1);j++){
                x = ara[i] + ara[j];
                //if(x == 7) cout<<ara[i]<<" "<<ara[j]<<endl;
                c += bisec(x) - j;
            }
        }
        printf("Case %d: %d\n",cas,c);
    }
    return 0;
}
