#include <stdio.h>

int main()
{
    double N1,N2,N3,N4,x,y,z;
    scanf("%lf %lf %lf %lf",&N1,&N2,&N3,&N4);
    x = ((N1*2)+(N2*3)+(N3*4)+N4)/10;


    printf("Media: %.1lf\n",x);
    if(x>=7){
        printf("Aluno aprovado.\n");
    }
    if(x<5){
        printf("Aluno reprovado.\n");
    }
    if(x>=5&&x<7){
        printf("Aluno em exame.\n");

        printf("Nota do exame: ");
        scanf("%lf",&y);
        z=(x+y)/2;
        if(z>=5){
            printf("Aluno aprovado.\n");
        }
        else{
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1lf\n",z);

    }

    return 0;
}
