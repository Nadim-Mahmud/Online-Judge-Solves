#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll i,j,k,a,b,c,d,n,m,sum=0;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        sum += n*a;
        if(b>0){
            c = (n-1)*(n)/2;
            sum += c*b;
        }
        else{
            c = n/2;
            if(n%2==0){
                sum += (c*(c+1)/2)*b;
                c--;
                sum += (c*(c+1)/2)*b;
            }
            else{
                sum += c*(c+1)*b;
            }
        }
    }
    printf("%.10lf\n",double((double)sum/(double)n));
    return 0;
}
