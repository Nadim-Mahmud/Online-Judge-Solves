#include<bits/stdc++.h>
#define sc(xx) scanf("%lld",&xx)
#define ll long long

using namespace std;

ll ara[1009];
ll cas=0,t,j,m,n,a,b,l;

bool check(ll x){
    ll sum = 0,c=1,i;
    //cout<<n<<m<<endl;
    for(i=1;i<=n;i++){
        //cout<<"r"<<endl;
        sum += ara[i];
        if(sum > x){
            sum = ara[i];
            c++;
        }

        //cout<<ara[i]<<" "<<sum<<" "<<c<<endl;

        if(c > m)return 0;
        else if(c == m && i == n) return 1;
    }
    return 1;
}

ll bisec(){

    ll h = 1000000000,i,mid;
    while(h-l>5){
        mid = (l+h)/2;
        if(check(mid)){
            h = mid;
            //cout<<"ss1:";
            //cout<<l<<m<<h<<endl;
        }
        else{
            l = mid;
            //cout<<l<<m<<h<<endl;
        }


        //cout<<check(m)<<endl;
    }
    //cout<<l<<m<<h<<endl;
    for(l;l<h;l++){
        //cout<<l<<" "<<check(78)<<endl;
        if(check(l))break;
    }
    return l;
}

int main(){
    //freopen("1076.txt","r",stdin);
    ll i;
    sc(t);
    while(++cas<=t){
        l=0;
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%lld",&ara[i]);
            if(ara[i]>l) l = ara[i];
        }
        printf("Case %lld: %lld\n",cas,bisec());
    }
    //for(i=1;i<=3;i++) scanf("%lld",&ara[i]);

   //for(i=1;i<=100;i++){
            //cin>>i;
            //cout<<check(81)<<endl;
   // }
    return 0;
}
