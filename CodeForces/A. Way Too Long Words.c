#include<stdio.h>
#include<string.h>

int main()
{
    int a,i,j,t;
    char ar[110];

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",ar);
        a=strlen(ar);
        if(a>10) printf("%c%d%c\n",ar[0],a-2,ar[a-1]);
        else printf("%s\n",ar);
        strcpy(ar,"");
    }
    return 0;
}
