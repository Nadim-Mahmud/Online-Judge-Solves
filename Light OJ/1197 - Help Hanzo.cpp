#include<bits/stdc++.h>
#define ll long long
#define eps 10e-8
#define MX 100000
#define FR FR("input.txt","r",stdin);
using namespace std;
bool mr[MX+5],mark[100005];
int pr[1000005],v=0;

void simpsiv(void){

    int i,j,r=sqrt(MX)+1;
    pr[++v] = 2;
    for(i=3;i<=MX;i+=2){
        if(!mr[i]){
            pr[++v] = i;
            if(i<=r){
                for(j=i*i;j<=MX;j+=(i<<1)){
                    mr[j] = 1;
                }
            }
        }
    }
}

void segsiv(ll l, ll u){

    ll i,j,lt;
    if(l==1) mark[0] = 1;
    for(i=1;i<=v&&pr[i]*pr[i]<=u;i++){
        //cout<<l<<" "<<pr[i]<<endl;
        lt = l/pr[i];
        lt *= pr[i];
        if(lt<l) lt += pr[i];
        if(pr[i]==lt) lt += pr[i];
        //cout<<i<<endl;
        for(lt;lt<=u;lt+=pr[i]){
            //cout<<lt-l<<" "<<pr[i]<<endl;
            mark[lt-l] = 1;
        }
    }
}

/// 1
///2147383647 2147483647
int main()
{
    ll a,b,i,cas=0,t,j,cnt=0;
    simpsiv();
    cin>>t;
    while(++cas<=t)
    {
        scanf("%lld %lld",&a,&b);
        segsiv(a,b);
        cnt=0;
        for(i=a;i<=b;i++){
            if(!mark[i-a]) cnt++;
            else mark[i-a] = 0;
        }
        printf("Case %lld: %lld\n",cas,cnt);
    }
    return 0;
}
