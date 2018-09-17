#include<bits/stdc++.h>

using namespace std;

int use[100],p[100],n,c,k;

void per(int a,int n){

    int i;
    if(a == n+1){
        c++;
        //if(c>k) return;
        for(i=1;i<=n;i++) printf("%d",p[i]);
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++){
        //if(c>k) break;
        if(!(use[i])){
            use[i] = 1;
            p[a] = i;
            per(a+1,n);
            use[i] = 0;
        }
    }
}

int main(){

    int cas=0,t,i,j;
    cin>>t;
    while(++cas<=t){
        c = 0;
        memset(use,0,sizeof(use));
        scanf("%d %d",&n,&k);
        //cout<<0;
        per(65,n);
    }
    return 0;
}
