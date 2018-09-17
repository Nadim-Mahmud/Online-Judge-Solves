#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int ara[200];



long long fn(long long c3){

        long long m = 1,sum = 0,i;

        for(i = c3;i>=0;i--){

            sum += ara[i]*m;
            m += m;
        }

        return sum;
}

void shortt(long long c3,long long z){

    long long j,i,c;
    z = c3-z+1;

    for(i=c3;i>=0;i--){

        //icout<<ara[c3]<<endl;
        if(i==z) break;
        if(ara[i] == 0 && ara[i-1] ==1){
            ara[i] = 1;
            ara[i-1] = 0;
            i=c3+1;
        }
    }
}

int main(){

    long long t,n,m,i,k,c,x,a,b,c1,c3,sum,sum2,z;

    //freopen("1042.txt","r",stdin);

    cin>>t;


    for(k=1;k<=t;k++){

        scanf("%lld",&n);

        c = 0;
        c1 = 0;
        c3 = 0;
        ara[0] = 0;
        m = n;

        for(i=1;m != 0;i++){

            ara[i] = m%2;
            m = m/2;
            if(ara[i] == 1) c++;
            else if(ara[i] == 0) c1++;
            c3++;
        }

        reverse(ara+1,ara+c3+1);

       // cout<<fn(c3);
       // cout<<endl;

        z = 0;
        for(i = c3 ;i>= 0;i--){

            z++;
            if(ara[i] == 1 && ara[i-1] == 0){

                ara[i] = 0;
                ara[i-1] = 1;
                break;
            }
        }

        //for(i=0;i <= c3;i++) cout<<ara[i];
       // cout<<endl;


        //sum = fn(c3);

        shortt(c3,z);

        //for(i=0;i <= c3;i++) cout<<ara[i];
       // cout<<endl;

        sum2 = fn(c3);


        printf("Case %lld: %lld\n",k,sum2);
    }

    return 0;
}
