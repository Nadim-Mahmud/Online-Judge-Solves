#include<cstdio>

int main(){

    int a,c=0,i,n,j;
    scanf("%d",&a);
    while(a>0){
        c++;
        if(a==1) break;
       // printf("%d %d\n",a,i);
        for(i=2;i<=a;i=i*2){
        //printf("%d %d\n",a,i);
            if(i*2>a){
                a=a%i;
                break;
            }
        }
    }
    printf("%d\n",c);

    return 0;
}
