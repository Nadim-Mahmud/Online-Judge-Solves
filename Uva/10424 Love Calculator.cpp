#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int ds(char s[]){

    int i,c=0;
    for(i=0;s[i] != '\0';i++){
        if(s[i]>=65&&s[i]<=90) c += s[i] - 64;
        if(s[i]>=97&&s[i]<=122) c += s[i] - 96;
    }
    return c;
}

int sum(int c1){
    int c=0;
    while(c1>9){
        c += c1%10;
        c1 /= 10;
    }

    if(c1+c>9) return sum(c1+c);
    else return c1+c;
}

int main(){

    int n,i,c1,c2,mem,c;
    char str[30],s[30];
    double d;

    while(gets(str)){
        gets(s);

        c = 0;
        c1 = sum(ds(str));
        c2 = sum(ds(s));

        if(c2>c1) d = (double)c1/c2*100.0;
        else d = (double)c2/c1*100.0;

        printf("%.2lf %%\n",d);
    }

    return 0;
}

