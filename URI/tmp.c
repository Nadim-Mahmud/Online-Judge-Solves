#include<stdio.h>
#include<string.h>


int main(){

    int i,j,x,y,c,sum;

    char str[1000],a[1000],b[100];

    scanf(" %[^\n]",str);

    sscanf(str,"%s %s",a,b);

    //if(0 = strcmp(b,"bin")){
        sum = 0;

        x = strlen(a);
        c=0;
        for(x;x>=0;x--){

            c++;
            y=1;
            for(i=1;i<=c;i++){
                y = y*2;
            }

            sum += a[x]*y;
        }
   // }
    printf("%d\n",sum);



    return 0;
}

