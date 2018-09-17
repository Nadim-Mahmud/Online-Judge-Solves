#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    long long ac,n,t,i,j,cas=0,a;
    string str;


    cin>>t;
    while(++cas<=t){

        ac = 0;

        scanf("%lld",&n);

        printf("Case %lld:\n",cas);

        for(i=1;i<=n;i++){
            cin>>str;

            if(str == "donate"){
                scanf("%lld",&a);

                ac += a;
            }
            else if(str == "report") printf("%lld\n",ac);
        }
    }
    return 0;
}
