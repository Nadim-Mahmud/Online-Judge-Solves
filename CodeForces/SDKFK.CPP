#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long a[n],b[n];
    for(int i=0;i<n;++i)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<m;++i)
    {
        scanf("%lld",&b[i]);
    }
    long long g=a[1]-a[0];
    for(int i=2;i<n;++i)
    {
        g=__gcd(g,a[i]-a[i-1]);
    }
    for(int i=0;i<m;++i)
    {
        if(g%b[i]==0)
        {
            printf("YES\n");
            printf("%lld %d",a[0],i+1);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
