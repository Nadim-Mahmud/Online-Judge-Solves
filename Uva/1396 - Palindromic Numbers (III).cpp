#include<bits/stdc++.h>

using namespace std;

char s[100009];
int t,cas=0,i,j,a,b,c,w,y,z,ln,m,c1,x,c2;


void fn2(void){
    c2=1;
    for(i=0;i<=w;i++){
        if(i==0||i==w) cout<<1;
        else printf("%d",0);
    }
}
void fn1(int l){
    if(m!=0){
        if(s[ln]!=9){
            s[ln]+=1;
            s[ln+1] = s[ln];
        }
        else if(s[ln-1] != 9){
            s[ln-1] += 1;
            s[ln+1] = s[ln];
        }
        else s[w-m-1]=s[m-1]+=1;
    }
    else if((w-1)%2==0) fn2();
}

int main(){

    freopen("1396.txt","r",stdin);
    cin>>t;
    while(++cas<=t){
        c = 0;
        m = 0;
        c1 = 0;
        c2 = 0;
        scanf("%s",s);
        w = strlen(s);
        //cout<<w<<endl;
        ln = (w-1)/2;
        x = s[ln];
        y = s[ln+1];
        z = s[ln+2];
        for(i=0,j=x-1;j>i;i++,j--){
            if(s[i]>s[j]) c1=1;

            if(s[i] != s[j]){
                c = 1;                               ///all swaping by previous
                s[j] = s[i];
            }
            else{
                if(s[i]==9&&s[i+1]==9&&m!=0) m = i; ///determinig last 99 sequence
                else m = 0;
            }
        }

        if((w-1)%2==0 && x<=y) fn1(ln); ///for even
        else{
            if((ln+1) != 9) s[ln+1] += 1;
            else if(!m) fn1(ln+1);
            else fn2();
        }
    if(w==1){
        if(s[0] == 9){
            printf("%d\n",11);
            c2 = 0;
        }
        else s[0] += 1,s[1] = '\0';
    }
    if(!c2)printf("%s\n",s);
    }
    return 0;
}
