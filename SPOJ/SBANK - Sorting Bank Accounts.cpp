#include<bits/stdc++.h>
using namespace std;

#define MX 100005

char * pn[MX];
string tmp;
char str[MX][35];
map<string,int>mp;

bool cmp(const char *s1,const char *s2){
    for(int i=0;s1[i];i++){
        if(s1[i]<s2[i]) return 1;
        if(s1[i]>s2[i]) return 0;
    }
    return 0;
}

int main(){
    int i,j,k,ts,cas=0,n,m,in=0,ins;
    //freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        getchar();
        in =  0;
        mp.clear();
        for(j=1;j<=n;j++){
            scanf(" %[^\n]s",str[j]);
//            gets(str[j]);
            if(mp[str[j]]==0){
                pn[in++] = str[j];
            }
            mp[str[j]]++;
        }
        sort(pn,pn+in,cmp);
        for(i=0;i<in;i++){
            printf("%s ",pn[i]);
            printf("%d\n",mp[pn[i]]);
        }
        if(cas!=ts)puts("");
    }
    return 0;
}
