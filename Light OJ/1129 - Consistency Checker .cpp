#include<bits/stdc++.h>
using namespace std;

struct node{
    bool end;
    node* next[11];
    node(){
        end = false;
        for(int i=0;i<11;i++){
            next[i] = NULL;
        }
    }
}*root;

bool insert(char *st){
    int i,in,mr=0;
    node *cur = root;
    for(i=0;st[i];i++){
        in = st[i]-'0';
        if(cur->end) mr = 1;
        if(cur->next[in]==NULL){
            cur->next[in] = new node();
        }
        cur = cur->next[in];
    }
    if(cur->end) mr=1;
    cur->end = 1;
    for(i=0;i<11;i++){
        if(cur->next[i]) mr = 1;
    }
    return mr;
}

void del(node *cur){
    for(int i=0;i<11;i++){
        if(cur->next[i])del(cur->next[i]);
    }
    delete(cur);
}

int main(){
    int i,j,k,l,n,m,ts,cas=0,cn=0;
    //freopen("test.txt","r",stdin);
    char str[20];
    cin>>ts;
    while(++cas<=ts){
        cn=0;
        root = new node();
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%s",str);
            if(insert(str))cn++;
        }
        printf("Case %d: ",cas);
        if(cn) puts("NO");
        else puts("YES");
        del(root);
    }
    return 0;
}
