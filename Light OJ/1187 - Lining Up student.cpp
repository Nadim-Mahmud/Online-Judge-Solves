#include<stdio.h>

int main(){
    int i,ans,n,ts,cas=0,x;
    scanf("%d",&ts);
    while(ts--){
        scanf("%d",&n);
        ans = 1;
        scanf("%d",&x);
        for(i=2;i<=n;i++){
            scanf("%d",&x);
            if(i-x<=ans) ans++;
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
