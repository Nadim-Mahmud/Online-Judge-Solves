#include<bits/stdc++.h>

using namespace std;

int main(){

    int ara[100],i,j,c,c1,d,x,n,l;

    cin>>x;

    for(n=2;n<=100;n++){
        l = 0;
        memset(ara,0,sizeof(ara));
        d = n;
        c = 0;
        c1 = 0;
        for(i=1;;i++){
            if(ara[i] == 0){
                c++;
                if(c==x){
                    //cout<<i<<endl;
                    ara[i] = 1;
                    c = 0;
                    c1++;
                    if(c1==d) break;
                }
            }
            //cout<<i<<" "<<ara[i]<<endl;
            if(c1==d) break;
            if(i==d) i=0;
            //l++;
            //if(l==40) break;
        }
        cout<<n<<" "<<i<<endl;;
    }
    return 0;
}
