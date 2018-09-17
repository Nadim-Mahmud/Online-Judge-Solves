#include<iostream>
#include<cstdio>

using namespace std;

struct ab{

    int x;
    int y;
};

int main(){

    ab a[1050],tmp;

    int t,n,i,j;

    for(i=1;i<=1049;i++){
        a[i].x = i;
        a[i].y = 0;
    }

    for(i=1;i<=1000;i++){
        for(j=i;j<=1000;j+=i){
            a[j].y++;
        }
    }

    for(i=1;i<=1000;i++){
        for(j=i;j<=1000;j++){

            if((a[i].y >= a[j].y)||(a[i].y == a[j].y && a[i].x > a[j].x )){

                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    scanf("%d",&t);

    for(i=1;i<=t;i++){

        scanf("%d",&n);

        printf("Case %d: %d\n",i,a[n].x);
    }


    return 0;
}
