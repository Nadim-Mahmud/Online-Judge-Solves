#include <stdio.h>

int main()
{
    int n,x,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);

        if(x==0){
            printf("NULL\n");
            continue;
        }
        if(x%2==0){
            if(x>0){
                printf("EVEN POSITIVE\n");
            }
            else{
                    printf("EVEN NEGATIVE\n");
        }
    }
    else{
        if(x>0){
            printf("ODD POSITIVE\n");
        }
        else{
            printf("ODD NEGATIVE\n");
        }
    }
    }
    return 0;
}
