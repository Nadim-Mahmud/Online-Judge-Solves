#include<bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    long long i,j,n,a,b,carr,c,l1,l2,sum;
    char s1[1000],s2[1000];
    //freopen("10035.txt","r",stdin);
    while(1){
        scanf("%lld %lld",&a,&b);
        c = 0,carr = 0;
        if(a == 0 && b == 0) break;
        sum = a + b;
        while(a&&b){
            //cout<<a%10<<"\n"<<b%10<<" "<<carr<<endl;
            if((a%10 + b%10 + carr) > 9) c++,carr = 1;
            else carr = 0;
            a /= 10 , b /= 10;
            //cout<<c<<endl;
        }
        //cout<<a<<b<<carr<<endl;
        ll c1 = 0,c2=0;
        if(a%10 == 9) c1 = 1;
        if(b%10 == 9) c2 = 1;
        if(carr == 1 && a >= 9){
            while(a){
                if(a%10 == 9 && c1 == 1) c++;
                else c1 = 0;
                a /= 10;
            }
        }
        else if(carr == 1 && b >= 9){
             while(b){
                if(b%10 == 9 && c2 == 1) c++;
                else c2 = 0;
                //cout<<b<<" "<<c<<endl;
                b /= 10;
            }
        }

        if(c==0) printf("No carry operation.\n");
        else if(c==1) printf("%lld carry operation.\n",c);
        else printf("%lld carry operations.\n",c);
    }
    return 0;
}
