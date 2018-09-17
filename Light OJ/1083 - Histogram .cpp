#include<bits/stdc++.h>
#define ll long long
#define MX 1000000000000000LL
#define p1(XX) cout<<"db1: "<<XX<<endl;
#define p2(XX,YY) cout<<"db2: "<<XX<<" "<<YY<<endl;
using namespace std;

int main()
{
    ll i,j,k,l,n,m,ts,cas=0,ar,mx,top,tmp,ara[30005],pr[30005],v,x,y,cn;
    stack<int>st;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        mx=v=cn=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&m);
            ara[i] = m;
            pr[i]=0;
            if(st.empty()) st.push(i);
            else if(ara[st.top()]<=m) st.push(i);
            //p1(i)
            //p2(ara[st.top()],m)
            if(ara[st.top()]>m){
              //  p1(i)
                while(!st.empty()&&ara[st.top()]>m){
                    top = st.top();
                    st.pop();
                    if(st.empty()) ar = ara[top]*i;
                    else ar = ara[top]*(i-st.top()-1) ;//+ pr[top]*ara[top];
                    mx = max(mx,ar);
                    pr[i]++;
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            top=st.top();
            st.pop();
            if(st.empty()){
                ar = ara[top]*n;
            }
            else{
                ar = ara[top]*(n-st.top()-1) ;//+ pr[top]*ara[top];
            }
            mx = max(mx,ar);
        }
        printf("Case %lld: %lld\n",cas,mx);
    }
    return 0;
}
