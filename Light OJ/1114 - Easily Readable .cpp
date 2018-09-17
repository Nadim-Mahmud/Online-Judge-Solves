#include<bits/stdc++.h>
#define ll long long
#define MX 100005
using namespace std;

int mp(char ch){
    if(ch<95) return (int) (ch - 'A');
    return (int) (ch - 'a' + 26);
}

struct node{
    bool end;
    int next[55];
    int cnt;
    void set(){
        cnt = 0;
        end = false;
        for(int i=0;i<=53;i++){
            next[i] = 0;
        }
    }
}ara[MX];

int ptr;

void insert(char *st){
    int i,in,x=0,y;
   // cout<<"=================\n";
    for(i=0;st[i];i++){
        if(st[i]==' ') continue;
        in = mp(st[i]);
        if(!ara[x].next[in]){
            ara[x].next[in] = ptr++;
            ara[ptr-1].set();
            //cout<<"yy\n";
        }
        x = ara[x].next[in];
        //cout<<x<<endl;
    }
    ara[x].end=1;
    ara[x].cnt++;
    //cout<<x<<" "<<st<<" "<<ara[x].cnt<<endl;
}

int search(char *st){
    int i,in,x=0,cn=0;
    for(i=0;st[i];i++){
        if(st[i]==' ')continue;
        cn++;
        in = mp(st[i]);
        if(!ara[x].next[in]) return 0;
        x = ara[x].next[in];
    }
    if(!cn) return 1;
    //cout<<st<<" "<<ara[x].cnt<<endl;
    return ara[x].cnt;
}

void strin(char *str){
    int ln;
    ln = strlen(str);
    if(ln>2){
        sort(str+1,str+ln-1);
    }
}

int main(){
    int i,j,k,l,m,n,ts,cas=0,ans,pre,v;
   // freopen("test.txt","r",stdin);
    char str[105],ch,st[10005];
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        ptr=1;
        ara[0].set();
        getchar();
        for(i=0;i<n;i++){
            gets(str);
            strin(str);
            //cout<<str<<endl;
            insert(str);
        }
        scanf("%d",&m);
        getchar();
        printf("Case %d:\n",cas);
        for(i=1;i<=m;i++){
            gets(st);
            pre=v=0;
            ans = 1;
            for(j=0;st[j];j++){
                if(st[j]==' '||st[j+1]=='\0'){
                    if(st[j+1]=='\0'&&st[j]!=' ') str[v++] = st[j];
                    str[v] = '\0';
                    strin(str);
                    ans *= search(str);
                    v=0;
                }
                else str[v++] = st[j];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
