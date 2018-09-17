#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    long long cas=0,t,x,y,sum,c,l,i,j,c1;    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
                                             // 1 2 3 3 4 4 5 5 5 6  6
    cin>>t;

    while(++cas <= t){

        scanf("%lld %lld",&x,&y);

        l = y - x;
        //cin>>l;
        sum = 0,c = 0,c1=0;

        while(sum < l){
            c1++;
            i=0;
            while(i < 2 && sum < l){
                sum += c1;
                c++;
                i++;
            }

        }

        printf("%lld\n",c);
    }
    return 0;
}

