#include<iostream>
#include<cstdio>
#include<cstring>


using namespace std;

bool last3(int n){
    if((n-1)%3 == 0) return 1;
    else return 0;
}

bool last2(int n){
    if(n%3 == 0) return 0;
    else return 1;
}

int main(){

    int n,x,t,cas=0;
    char str[100];

    cin>>t;
    while(++cas <= t){

        scanf("%d",&n);
        scanf("%s",str);
        if(!strcmp(str,"Alice")){
            if(!(last3(n)&&last2(n))) printf("Case %d: Alice\n",cas);
            else  printf("Case %d: Bob\n",cas);
        }
        else{
            if(last3(n)||last2(n)) printf("Case %d: Bob\n",cas);
            else  printf("Case %d: Alice\n",cas);
        }

    }
    return 0;
}
