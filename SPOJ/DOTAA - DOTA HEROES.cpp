#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,l,m,n,d,x,y,ts,cas=0;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d %d %d",&n,&m,&d);
        while(n--){
            scanf("%d",&x);
            while(x>d){
                x -= d;
                m--;
            }
        }
        if(m<=0) puts("YES");
        else puts("NO");
    }
    return 0;
}
