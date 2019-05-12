#include<bits/stdc++.h>
using namespace std;

#define MX 100005

char * pn[MX];
string tmp;
char str[MX][35];
map<string,int>mp;

bool cmp(const char *s1,const char *s2){
    //cout<<s1<<" "<<s2<<endl;
    for(int i=0;i<26;i++){
        if(s1[i]<s2[i]) return 1;
        if(s1[i]>s2[i]) return 0;
    }
    //puts("dd");
    return 0;
}

int main(){
    int i,j,k,ts,cas=0,n,m,in=0,ins;
    freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        scanf("%d",&n);
        tmp = "";
        in =  0;
        mp.clear();
        for(j=1;j<=n;j++){
            for(i=0;i<32;i++){
                scanf("%c",&str[j][i]);
            }
            str[j][i] = '\0';
           // gets(str[j]);
            //puts(str[j]);
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
