#include<iostream>
#include<cstdio>

using namespace std;

int ara[300],ara2[300];

int main(){

    int t,j,k,c1,c2,c3,i,x;

    char a[200],b[200];

    //freopen("1338.txt","r",stdin);

    cin>>t;

    for(k=1;k<=t;k++){

        for(i=1;i<=299;i++){
            ara[i] = 0;
            ara2[i] = 0;
        }

        c1 = 0;
        c2 = 0;
        c3 = 0;

        scanf(" %[^\n]",a);
        scanf(" %[^\n]",b);

        for(i=0;a[i] != '\0';i++){

            x = a[i];

            if(x > 95) x -= 32;

            if(x != ' '){
                ara[x]++;
                c1++;
            }
        }

        for(i=0;b[i] != '\0';i++){

            if(b[i] != ' '){
                x = b[i];
                if(x > 95) x -= 32;
                ara2[x]++;
                c2++;
            }
        }

        if(c2 > c1){

            for(i = 0;a[i] != '\0';i++){

                x = a[i];

                if(x > 95) x -= 32;

                if(x != ' '){

                    if(ara2[x] == 0) break;
                    else{
                        c3++;
                        ara2[x]--;
                    }
                }
            }
        }
        else{

          for(i=0;b[i] != '\0';i++){

                x = b[i];

                if(x > 95) x -= 32;

                if(x != ' '){
                    if(ara[x] == 0) break;
                    else{
                        c3++;
                        ara[x]--;
                    }
                }
            }
        }

        if(c1<=c2 && c3 == c1) printf("Case %d: Yes\n",k);
        else if(c2<c1 && c2==c3) printf("Case %d: Yes\n",k);
        else printf("Case %d: No\n",k);

    }

    return 0;
}
