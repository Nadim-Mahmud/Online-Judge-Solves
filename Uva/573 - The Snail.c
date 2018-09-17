#include<stdio.h>

int main(){

    int c,i;
    float h,x,y,f,a;

    for(i=1;;i++){

        c=0;
        a=0;
        scanf("%f %f %f %f",&h,&x,&y,&f);
        if(h==0) break;
        f=x*(f/100);

        for(;;){

            c++;
            if(c!=1&&x>0) x=x-f;
            a=a+x;

            if(a>h){
                printf("success on day %d\n",c);
                break;
            }

            a=a-y;
            if(a<0){
                printf("failure on day %d\n", c);
                break;
            }
        }
    }
    return 0;
}
