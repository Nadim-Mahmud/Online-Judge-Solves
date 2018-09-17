#include<bits/stdc++.h>
#define sc(xx) scanf("%lld",&xx)
#define ll long long

using namespace std;

int ara[1009],n,k,l,a,b,ara2[1009],v = 0;

int check(int x){
    int i,sum=0,c=1;
    for(i=1;i<=n;i++){
        sum += ara[i];
        if(sum>x){
            sum = ara[i];
            c++;
        }
        if(c > (k+1)) return 0;
    }
    return 1;
}

int bisec(void){
    int h = 10000000,i,mid;
    while(h-l>5){
        mid = (l+h)/2;
        if(check(mid)){
            h = mid;
        }
        else{
            l = mid;
        }
    }
    for(l;l<h;l++){
        if(check(l))break;
    }
    return l;
}

void trunc(int x){
    int i,j=1,c=0,sum=0,c1=1,c2=0,a,b;
    k++;
    c = k;
    for(i=1;i<=n;i++){
        if(sum+ara[i]>x||c==n-i+2){
            printf("%d\n",sum);
            c--;
            sum=0;
        }
        sum+=ara[i];
    }
    printf("%d\n",sum);
}

int main(){

    int cas=0,t,i,j,c,p,ans,v1,sum=0;
    //freopen("1048.txt","r",stdin);
    //freopen("1048.out","w",stdout);
    sc(t);
    while(++cas<=t){
        l = 0;
        v = 0;
        scanf("%d %d",&n,&k);
        n++;
        for(i=1;i<=n;i++){
            sc(ara[i]);
            if(l < ara[i]) l = ara[i];
        }
        ans = bisec();
        printf("Case %d: %d\n",cas,ans);
        trunc(ans);
        //for(i=1;i<=k+1;i++ ) printf("%d\n",ara2[i]);
    }
    return 0;
}


///Garbage:::::::::::::::::::::::::::::::::::::::::::::

/* for(i=1;i<=k;i++){
        sum = 0;
        //cout<<"nc: "<<n-c<<" "<<k-v<<endl;
        if((n-j-1) > k-v){
            for(;j<=n;j++){
                if(sum+ara[j]>x){
                    ara2[++v] = sum;
                    c = j-1;
                    //cout<<v<<" "<<c<<" "<<sum<<endl;
                    break;
                }
                sum+=ara[j];
            }
        }
        else if(n-j-1) == k-v)
            if(sum) ara2[++v] = sum;
        else break;
    }
    //cout<<c<<v<<endl;
    c = j;
    a = (n-c) - (k-v);
    sum =0;
    //cout<<c+1<<endl;
    if(a>0){
        a += c+1;
        //cout<<"aa: "<<a<<endl;
        for(j=c+1;j<=a;j++) sum += ara[j];
        ara2[++v] = sum;
        for(j=a+1;j<=n;j++) ara2[++v] = ara[j];
        //cout<<"ssss"<<v<<endl;
    }
    else for(j=c+1;j<=n;j++) ara2[++v] = ara[j];*/
