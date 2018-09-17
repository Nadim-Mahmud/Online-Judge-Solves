#include <stdio.h>

int main()

{


    if(A>=B+C){

        printf("NAO FORMA TRIANGULO\n");
    }
    else if(A*A==B*B+C*C){
        printf("TRIANGULO RETANGULO\n");
    }
    else if(A*A> B*B + C*C){
        printf("TRIANGULO OBTUSANGULO\n");
    }
    else if(A*A<B*B+C*C){
        printf("TRIANGULO ACUTANGULO\n");
    }
    if(A==B&&B==C){
        printf("TRIANGULO EQUILATERO\n");
    }
    if(A==B&&B!=C||B==C&&C!=A||C==A&&A!=B){
        printf("TRIANGULO ISOSCELES\n");
    }
    return 0;

}
