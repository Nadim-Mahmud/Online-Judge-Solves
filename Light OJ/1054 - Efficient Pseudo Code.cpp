#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MD 1000000007

using namespace std;

bool ap[100005];
int pr[50000],N=100000,v=0;

void siv()
{
    int i,j,rt;
    rt=sqrt(N)+1;
    for(i=2;i<=N;i++){
        if(!ap[i]){
            pr[++v] = i;
            if(i<=rt){
                for(j=i*i;j<=N;j+=i){
                    ap[j]=true;
                }
            }
        }
    }
}

ll B;//n,m;

ll bgM(ll p)
{
    if(p==0)return 1;
    ll r;
    r=bgM(p/2);
    r=(r*r)%MD;
    if(p%2) return (r*B)%MD;
    else return r;
}

pii extnuc(ll a,ll b)
{
    if(b==0)return pii(1,0);
    pii d=extnuc(b,a%b);
    return pii(d.second,d.first-d.second*(a/b));
}

ll modi(ll n)
{
    pii d=extnuc(n,MD);
    return ((d.first%MD)+MD)%MD;
}

int main(){

    int cas=0,t;
    ll n,m,sum,i,j,x,cnt=0;
    siv();
    cout<<v<<endl;
    scanf("%d",&t);

    while(++cas<=t){

        cnt = 0,sum=1;
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=v&&pr[i]*pr[i]<=n;i++){
            cnt=0;
            while(n%pr[i]==0){
                cnt++;
                n /= pr[i];
            }
            B = pr[i];
            if(cnt){
                cnt *= m;
                sum *= ((bgM(cnt+1)-1+MD)%MD)*(modi(B-1))%MD;
            }
            sum = sum%MD;
            //printf("%lld\n",sum);
        }
        B = n;
        //cout<<B<<endl;
        if(n>1){
            sum *= ((bgM(m+1)-1+MD)%MD)*(modi(B-1))%MD;
            sum = sum%MD;
        }

        printf("Case %d: %lld\n",cas,sum);
    }
    return 0;
}

