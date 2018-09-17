#include<bits/stdc++.h>
using namespace std;
int ans=0;
int mp(char ch){
    if(ch=='A') return 1;
    if(ch=='C') return 2;
    if(ch=='G') return 3;
    if(ch=='T') return 4;
}

struct node{
    bool end;
    int cn;
    node* next[5];
    node(){
        end = false;
        cn=0;
        for(int i=0;i<5;i++){
            next[i] = NULL;
        }
    }
}*root;

void insert(char *st){
    int i,in;
    node *cur = root;
    for(i=0;st[i];i++){
        in = mp(st[i]);
        if(cur->next[in]==NULL){
            cur->next[in] = new node();
            //cout<<"yes\n";
        }
        cur = cur->next[in];
        cur->cn += i+1;
        //cout<<i<<" "<<st[i]<<" "<<cur->cn<<endl;
        ans = max(ans,cur->cn);
    }
    cur->end=true;
}

void del(node *cur){
    for(int i=0;i<5;i++){
        if(cur->next[i]) del(cur->next[i]);
    }
    delete(cur);
}

int main(){
    int i,j,k,n,m,ts,cas=0;
    char str[100];
   // freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        ans = 0;
        root = new node();
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%s",str);
            insert(str);
        }
        del(root);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
