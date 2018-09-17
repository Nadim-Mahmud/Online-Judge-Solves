#include <stdio.h>

int main()
{
    double A,B,C,p,a;

    scanf("%lf %lf %lf",&A,&B,&C);

    if(A+B>C&&B+C>A&&C+A>B){
        p=A+B+C;
        printf("Perimetro = %.1lf\n",p);
    }
    else{
        a= (C/2)*(A+B);
        printf("Area = %.1lf\n",a);
    }
    return 0;
}
