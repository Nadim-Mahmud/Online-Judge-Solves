#include<bits/stdc++.h>
#define MX  50005
using namespace std;

struct node{
    int x,y,a,b;
    int c;
}ara[MX],seg[MX*4];

long long c=0;

void creat(int l,int h,int pos)
{
    c++;
    if(l==h){
        seg[pos] = ara[l];
        seg[pos].c=1;
        return;
    }

    int mid = (l+h)/2;

    creat(l,mid,pos*2+1);
    creat(mid+1,h,pos*2+2);
    seg[pos].x = max(seg[pos*2+1].x,seg[pos*2+2].x);
    seg[pos].y = min(seg[pos*2+1].y,seg[pos*2+2].y);
    seg[pos].a = min(seg[pos*2+1].a,seg[pos*2+2].a);
    seg[pos].b = max(seg[pos*2+1].b,seg[pos*2+2].b);
    seg[pos].c = seg[pos*2+1].c + seg[pos*2+2].c;
}

int query(int q,int pos)
{
    c++;

    if(q<seg[pos].a||q>seg[pos].b) return 0;
//    cout<<q<<endl;
//    cout<<seg[pos].x<<" "<<seg[pos].y<<endl;
    if(seg[pos].x<=q&&q<=seg[pos].y) return seg[pos].c;
//    cout<<pos<<endl;

    return query(q,pos*2+1) + query(q,pos*2+2);
}

int main()
{
    int i,j,k,ts,cas=0,n,q,a,b,cn=0;
    freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        c=0;
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++){
            scanf("%d %d",&ara[i].x,&ara[i].y);
            ara[i].a = ara[i].x;
            ara[i].b = ara[i].y;
        }
        creat(0,n-1,0);
//        for(i=0;i<10;i++){
//            cout<<i<<endl;
//            cout<<seg[i].x<<" "<<seg[i].y<<endl;
//            cout<<seg[i].a<<" "<<seg[i].b<<endl;
//        }
        printf("Case %d:\n",cas);
        for(i=1;i<=q;i++){
            scanf("%d",&a);
            a = query(a,0);
           // printf("%d %d\n",i,q);
        }
        cout<<c<<endl;
    }
    return 0;
}
