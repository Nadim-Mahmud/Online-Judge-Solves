#include <stdio.h>

int main()
{
    int i,n;
    long int x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%ld %ld",&x,&y);
        if(x==y) printf("=\n");
        if(x>y) printf(">\n");
        if(x<y) printf("<\n");
    }
    return 0;
}
