#include<bits/stdc++.h>
#define MX 100005
using namespace std;
bool seg[4*MX];
char ara[4*MX];

void creat(int low,int hi,int pos)
{
    if(low==hi){
        seg[pos] = (int)ara[low]-'0';
        return;
    }
    int mid = (low+hi)/2;

    creat(low,mid,pos*2+1);
    creat(mid+1,hi,pos*2+2);
    seg[pos] = 0;
}

void update(int low,int high,int ulow,int uhigh,int pos)
{
    if(low>high) return ;

    if(ulow>high||uhigh<low) return;

    if(ulow<=low&&uhigh>=high){
        seg[pos] ^= 1;
        return;
    }

    int mid = (high+low)/2;

    update(low,mid,ulow,uhigh,pos*2+1);
    update(mid+1,high,ulow,uhigh,pos*2+2);
}

int query(int low,int high,int qr,int pos)
{
    if(low>high) return 0;
    if(qr>high||qr<low) return 0;

    if(qr<=low&&qr>=high) return seg[pos];

    int mid = (low+high)/2;

    if(qr<=mid) return query(low,mid,qr,pos*2+1)^seg[pos];
    else return query(mid+1,high,qr,pos*2+2)^seg[pos];
}

int main()
{
    int a,b,n,q,cas=0,ts,i,j;
///    freopen("test.txt","r",stdin);
    char ch;
    cin>>ts;
    while(++cas<=ts){
        scanf("%s",ara);
        n = strlen(ara);
        creat(0,n-1,0);
//        for(j=0;j<=30;j++) cout<<seg[j]<<" ";
//        cout<<endl;
        scanf("%d",&q);
        getchar();
        printf("Case %d:\n",cas);
        for(i=1;i<=q;i++){
            scanf("%c",&ch);
            if(ch =='I'){
                scanf("%d %d",&a,&b);
                getchar();
                update(0,n-1,a-1,b-1,0);
//                cout<<" dd\n";
//                for(j=1;j<=30;j++) cout<<seg[j]<<" ";
//                cout<<endl;
            }
            else{
                scanf("%d",&a);
                getchar();
                printf("%d\n",query(0,n-1,a-1,0));
            }
        }
    }
    return 0;
}

