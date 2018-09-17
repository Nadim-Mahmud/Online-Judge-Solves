#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
    int n,b,h,w,c,mini,x,i,j,y,cu;
    while(scanf("%d %d %d %d",&n,&b,&h,&w) !=EOF )
    {
        cu=0;
        y=0;
        for(i=1;i<=h;i++)
        {
            cin>>c;
            for(j=1;j<=w;j++)
            {
                cin>>x;
                if(x>=n&&(n*c)<=b)
                {
                    if(cu==0) y=c;
                    if(y>c) y=c;
                    cu++;
                }
            }
        }
        if(y==0) cout<<"stay home"<<"\n";
        else cout<<n*y<<"\n";
    }
    return 0;
}
