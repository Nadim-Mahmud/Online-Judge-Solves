#include<iostream>
#include<cstdio>

using namespace std;

bool leap(long long x){

    if(x%100==0){
        if(x%400==0) return true;
        else return false;
    }
    else if(x%4 == 0) return true;
    else return false;
}


long long fn(long long y1,long long y2){

    long long x,c  = 0;

    while(1){
        if(y1%100 == 0) break;
        y1++;
    }
    while(1){
        if(y2%100 == 0 ) break;
        y2--;
    }

    if((y1 == y2)){
        if(y1%400 != 0) c++;
    }
    else{
        while(y1%400 != 0){
            y1 += 100;
            c++;
        }
        while(y2%400 != 0){
            y2 -= 100;
            c++;
        }
         x = y2 - y1;
         if(x != 0) c = c + x/100 - (x/400 );
    }
    return c;
}
int main(){

        long long d1,d2,y1,y2,i,c1,c2,t,k,x,cx;
        char a;
        string str1,str2;

        //freopen("1414.txt","r",stdin);

        cin>>t;

        for(k=1;k<=t;k++){

            x = 0 ;
            c1 = 0;

            cin>>str1;
            scanf("%lld",&d1);
            scanf(" %c",&a);
            scanf("%lld",&y1);

            cin>>str2;
            scanf("%lld",&d2);
            scanf(" %c",&a);
            scanf("%lld",&y2);

            if(y1 == y2){

                if((str1 == "January"||str1 == "February") && (str2 != "January"&& str2 != "February")){
                    if(leap(y1)) c1++;
                }

                if(str2 == "February"){
                    if(d2 == 29){
                        if(leap(y1)) c1++;
                    }
                }
            }

            if(y1 != y2){

                if(str1 == "January"||str1 == "February"){
                    if(leap(y1)) c1++;
                }

                if(str2 == "February"){

                    if(d2==29){
                        if(leap(y2))c1++;
                    }
                }
                else if(str2 != "January"){
                    if(leap(y2))c1++;
                }

                while(1){
                     y1++;
                     if(y1%4 == 0) break;
                }

                while(1){
                     y2--;
                     if(y2%4 == 0) break;
                }

                x = ((y2-y1)/4 + 1) - fn(y1,y2);
            }
           printf("Case %lld: %lld\n",k,x+c1);
    }
    return 0;
}

