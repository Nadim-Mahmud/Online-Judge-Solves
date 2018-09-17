///LOJ 1207 - Posters for Election

#include<bits/stdc++.h>
#define pii pair<int,int>
#define P(X) cout<<"db "<<X<<endl;
#define P2(X,Y) cout<<"db2 "<<X<<" "<<Y<<endl;
#define MX 200005
using namespace std;

int seg[4*MX],lazy[4*MX];

void update(int l,int h,int lw,int hi,int pos){
    //cout<<lw<<" "<<hi<<" --- "<<pos<<endl;
    if(lw>hi) return ;
    if(lazy[pos]!=0){
        seg[pos] = 1;
        if(lw!=hi){
            lazy[pos*2] = 1;
            lazy[pos*2+1] = 1;
        }
        lazy[pos] = 0;
    }
    if(l>hi||h<lw) return;
    //P("yes")
    if(lw>=l&&hi<=h){
        seg[pos] = 1;
        //P2("setttttttttting",pos)
        if(lw!=hi){
            lazy[pos*2] = 1;
            lazy[pos*2+1] = 1;
        }
        return ;
    }
    //cout<<"=======\n";
    int m = (lw+hi)/2;
    update(l,h,lw,m,pos*2);
    update(l,h,m+1,hi,pos*2+1);
    seg[pos] = seg[pos*2] & seg[pos*2+1];
}

int query(int l,int h,int lw,int hi,int pos){
    //cout<<pos<<endl;
    //cout<<lw<<" "<<hi<<" --- "<<pos<<endl;
    if(lw>hi) return 1;
    if(lazy[pos]!=0){
        seg[pos] =  1;
        if(lw!=hi){
            lazy[pos*2] = 1;
            lazy[pos*2+1] = 1;
        }
        lazy[pos] = 1;
    }
    if(l>hi||h<lw) return 1;
    if(l<=lw&&hi<=h) {
        //P2("retering pos val ",seg[pos]);
        return seg[pos];
    }
    int m = (lw+hi)/2;
    return query(l,h,lw,m,pos*2) & query(l,h,m+1,hi,pos*2+1);
}

int main(){
    int i,j,k,n,m,cas=0,ts,x,y,a,b,h,cn,mx;
    //freopen("test.txt","r",stdin);
    pii pr;
    stack<pii>st;
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        cn=mx=0;
        memset(seg,0,sizeof seg);
        memset(lazy,0,sizeof lazy);
        for(i=1;i<=n;i++){
            scanf("%d %d",&x,&y);
            st.push(pii(x,y));
            mx = max(mx,y);
        }
        for(i=1;i<=n;i++){
            pr = st.top();
            st.pop();
            a = pr.first;
            b = pr.second;
            //cout<<a<<"::"<<b<<endl;
            if(!query(a,b,1,mx,1)) cn++;
            update(a,b,1,mx,1);
        }
        printf("Case %d: %d\n",cas,cn);
    }
    return 0;
}
