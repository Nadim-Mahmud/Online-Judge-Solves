#include<bits/stdc++.h>

using namespace std;

char s[100009];
int t,cas=0,i,j,a,b,c,w,y,z,ln,m,c1,x,c2,pl1,pl2,lm,um,dum;


void fn2(int lm,int um){
    //cout<<lm<<um<<endl;
    if(c2!=1){
        for(i=0;s[i]!='\0';i++){
            if(i==lm){
                for(i=lm;i<=um;i++){
                    if(i==0) printf("1");
                    if((w-1)==i) printf("1");
                    else printf("0");
                }
                if(i==w) break;
            }
            printf("%c",s[i]);
        }
    }
    else printf("11");
    cout<<endl;
}
void fn1(int l){     ///0 1 2 3 4 5 6 7 8 9
    //cout<<l<<endl;
    if(s[l]!='9'){
        lm = l+1;
        um = w-lm-1;
        s[l]+=1;
        s[w-1-l] = s[l];
       // cout<<lm<<um<<endl;
    }
    else if(m==0){
        lm = 0;
        um = w-1;
    }
    else{
        lm = m;
        um = w-lm-1;
        s[w-m]=s[m-1]+=1;
    }
}

int main(){

    //freopen("1396.txt","r",stdin);
    //1freopen("1396a.txt","w",stdout);
    cin>>t;
    while(++cas<=t){
        c = 0,m = -2,c1 = 0,c2 = 0,pl1=0,pl2=0,lm=-2,um=-2;
        scanf("%s",s);
        w = strlen(s);
        if(w%2==0) ln = (w-1)/2;
        else ln = (w-2)/2;

        x = s[ln];
        y = s[ln+1];
        z = s[ln+2];
        //cout<<x<<z<<endl;
        for(i=0,j=w-1;j>=i;i++,j--){
            if(s[i]>s[j]){
                c1=1;
                pl1 = i;
            }
            if(s[i] != s[j]){
                c = 1;
                s[j] = s[i];
                pl2 = i;
            }
            if(s[i]=='9'&&m==-2) m = i;
            else if(s[i] != '9') m = -2;
            //cout<<s[i]<<m<<endl;
        }
        //cout<<c1<<endl;
        //cout<<"yes: "<<s<<endl;
        //cout<<s[0]<<endl;
        if(w==1){
            if(s[0]=='9') c2 = 1;
            else s[0] += 1,s[1] = '\0';
        }
        else if(c1 == 1 && pl1>=pl2) dum=0;
        else if(w%2==0&&x<=y) fn1(ln);
        else if(x<=z){
            //cout<<"yes"<<endl;
            if(s[ln+1]!='9'){
                //cout<<"yes\n";
                s[ln+1] += 1;
            }
            else{
                //cout<<"yes\n";
                fn1(ln);
            }
        }

    printf("Case %d: ",cas);
    fn2(lm,um);
    //if(!c2)printf("%s\n",s);
    }
    return 0;
}

