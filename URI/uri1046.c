#include <stdio.h>

int main()
{
    int x,y,z;
    scanf("%d %d",&x,&y);

    if(x<y){
        z=y-x;
        printf("O JOGO DUROU %d HORA(S)\n",z);
    }
    if(x>y){
        z=(24-x)+y;
        printf("O JOGO DUROU %d HORA(S)\n",z);
    }
    if(x==y){
        z=24;
        printf("O JOGO DUROU %d HORA(S)\n",z);
    }
    return 0;
}
