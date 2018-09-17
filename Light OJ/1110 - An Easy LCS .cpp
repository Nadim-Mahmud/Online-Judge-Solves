#include<bits/stdc++.h>
using namespace std;

string st1,st2,dp[105][105];

string mn(string a,string b){
    //cout<<a<<" "<<b<<endl;
    if(a.size()==b.size()){
        if(a<b) return a;
        else return b;
    }
    else{
        if(a.size()>b.size()) return a;
        else return b;
    }
}

string lcs(int i,int j){
    if(i>=st1.size()||j>=st2.size()) return "";
    if(dp[i][j]!="0"){
        return dp[i][j];
    }
    string ret;
    if(st1[i]==st2[j]){
        ret = st1[i] + lcs(i+1,j+1);
    }
    else{
        //cout<<i<<" "<<j<<endl;
        ret = mn(lcs(i+1,j),lcs(i,j+1));
    }
    //cout<<ret<<endl;
    return dp[i][j] = ret;
}

void clr(){
    for(int i=0;i<=100;i++){
        for(int j = 0;j<=100;j++){
            dp[i][j] = "0";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
   // cin.tie(0);
    //cout.tie(0);
    int i,j,k,l,n,m,ts,cas=0;
    string st;
   // freopen("test.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts){
        clr();
        cin>>st1>>st2;
        printf("Case %d: ",cas);
        st=lcs(0,0);
        if(st.size()==0) printf(":(\n");
        else cout<<st<<"\n";
    }
    return 0;
}
