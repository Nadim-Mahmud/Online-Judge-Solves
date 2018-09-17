#include <stdio.h>

int main()

{
    char ch;
    double a,b,c;
    scanf("%s", &ch);
    scanf("%lf %lf",&a,&b);
    c= a +b*.15;
    printf("TOTAL = R$ %.2lf\n",c);

    return 0;
}
