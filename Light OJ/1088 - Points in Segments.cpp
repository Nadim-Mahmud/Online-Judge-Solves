#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int ara[100009];

int bin(int n,int h){

    int m,l=1,c;
    while(1){
        m = (l+h)/2;
        //cout<<l<<m<<h<<endl;

        if(ara[m] == n)return m;
        else if(ara[m]<n&&n<ara[m+1]) return -1*m;
        else if(l>=h) return -1*m;

        if(ara[m]>n) h = m-1;
        else if(ara[m]<n) l = m+1;
    }
}

int main(){

    int cas=0,t,i,n,q,x,y,l,h;
    //freopen("1088.txt","r",stdin);
    scanf("%d",&t);
    while(++cas<=t){
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&ara[i]);

        printf("Case %d:\n",cas);
        for(i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            //cout<<x<<" "<<y<<endl;
            if(x<=ara[1]) l = 1;
            else l = bin(x,n);
            if(y>=ara[n]) h = n;
            else h = bin(y,n);
            //cout<<l<<" "<<h<<endl;
            if((l==h)&&(l<0&&h<0)) printf("0\n");
            else if((abs(l)==abs(h))&&l>0) printf("1\n");
            else{
                if(l<0){
                    l = abs(l);
                    l++;
                }
                h = abs(h);
                //cout<<l<<h<<endl;
                printf("%d\n",(h-l)+1);
            }
        }
    }
    return 0;
}
