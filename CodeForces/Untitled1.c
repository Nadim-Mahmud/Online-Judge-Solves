#include<stdio.h>
#include<algorithm>

int main()
{
    int i, a[1000];

    for(i=0;i<100;i+=2){
        a[i]=i;
        a[i+1]=i-9;
    }
    sort(a,a+101);

    for(i=0;i<100;i++){
        printf("%d\n",a[i]);
    }
}
