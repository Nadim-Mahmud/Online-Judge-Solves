#include<stdio.h>
#include<string.h>


int main()
{
    int i;
    char a[100];
    scanf("%s",a);
    printf("%s\n",a);
    strcpy(a,"");
    printf("%s\n",a);
    for(i=0;a[i]!='\0';i++)
    {
        printf("%d",a[i]);
    }

    return 0;
}
