#include<iostream>
#include<cstdio>

using namespace std;


int main(){

    int vol,i,t,k,l,w,h,mx,mini,n,j,c;

    string name,thi,suf;

    //freopen("1249.txt","r",stdin);

    cin>>t;

    for(k=1;k<=t;k++){

        c = 0;

        scanf("%d",&n);

        for(j=1;j<=n;j++){

            cin>>name;
            scanf("%d %d %d",&l,&w,&h);

            vol = l*w*h;

            if(j==1){
                mx = vol;
                mini = vol;
                thi = name;
                suf = name;
            }

            if(mx<vol){
                thi = name;
                mx = vol;
            }
            if(mini>vol){
                suf = name;
                mini = vol;
                c--;
            }
            if(mini==vol) c++;
        }

        if(mx = mini && n == c) printf("Case %d: no thief\n",k);
        else if(n != 2 && c == (n-1)) cout<<"Case "<<k<<": "<<thi<<" took chocolate from all\n";
        else cout<<"Case "<<k<<": "<<thi<<" took chocolate from "<<suf<<endl;
    }


    return 0;
}
