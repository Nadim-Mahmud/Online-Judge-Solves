#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a[1000000];

int main(){

    int z,i,j,k,l,r,b,c=0,c1=0,n,x,y;

    //freopen("1212.txt","r",stdin);

    string st;

    cin>>z;

    for(k=1;k<=z;k++){

        c = 0;
        c1 = 0;
        l = 55555;
        r = 55555;

        scanf("%d %d",&n,&b);
        printf("Case %d:\n",k);

        for(i=1;i<=b;i++){

            cin>>st;
            //cout<<l<<" "<<r<<endl;
            if(c == 0){
                l = 55555;
                r = 55555;
            }

                if(st == "pushLeft"){
                    cin>>y;
                    c++;
                    if(c > n){
                        printf("The queue is full\n");
                        c--;
                    }
                    else{
                        a[l] = y;
                        l--;
                       // cout<<"         "<<l<<endl;
                        c1++;
                        if(c1 == 1) r++;

                        printf("Pushed in left: %d\n",y);
                    }
                }
                else if(st == "pushRight"){
                    cin>>y;
                    c++;
                    if(c > n){
                        printf("The queue is full\n");
                        c--;
                    }
                    else{
                        a[r] = y;
                        r++;
                        c1++;
                        if(c1 == 1) l--;
                       // if()
                        printf("Pushed in right: %d\n",y);
                    }
                }
                else if(st == "popLeft"){
                    if(c == 0){
                        printf("The queue is empty\n");
                    }
                    else{
                        l++;
                        //cout<<a[l]<<" "<<l<<endl;
                        printf("Popped from left: %d\n",a[l]);
                        c--;
                        c1--;
                        //if(c == 0) r = 55555;
                        //a[l] = 0;
                    }
                }
                else if(st == "popRight"){

                    if(c == 0){
                        printf("The queue is empty\n");
                    }
                    else{
                        r--;
                        printf("Popped from right: %d\n",a[r]);
                        c--;
                        c1--;
                        //if(c == 0) l = 55555;
                        //a[r] = 0;
                    }

            }
        }
    }

    return 0;
}
