#include<stdio.h>


bool ara[10000001];
int ara1[664610];
int n = 1;

void prime(){

    int i,j;
    ara[1] = 1;
    for(i=2;i<=10000000;i++){
        if(ara[i] != 1){
            ara1[n++] = i;
            for(j=i+i;j<=10000000;j += i){
                ara[j] = 1;
            }
        }
    }
}

int main(){

    int i,j,t,cas = 0,a,x,y,c;
    prime();
    scanf("%d",&t);
    while(++cas <= t){
        c = 0;
        scanf("%d",&a);
        x = a/2;
        for(i=1;i<=n;i++){

            if(ara1[i] > x) break;
            y = a - ara1[i];
            if(ara[y] != 1) c++;
        }
        printf("Case %d: %d\n",cas,c);
    }

    //for(i=1;i<=n;i++) cout<<i<<" "<<ara1[i]<<endl;
    return 0;
}
