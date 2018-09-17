#include<bits/stdc++.h>

using namespace std;

char ara[25][25];
int w,h;

void fn(){
    for(int i=0;i<h;i++) cout<<ara[i]<<endl;
}

int rec(int i, int j){

    //cout<<ara[i][j]<<" "<<i<<" "<<j<<endl;

    if(i<0||i>(h-1)||j<0||j>(w-1)) return 0;
    int sum  = 1;

    if(ara[i-1][j]=='.'){
       // cout<<1<<endl;
        ara[i-1][j] = 'x';
        sum += rec(i-1,j);
    }
    if(ara[i+1][j]=='.'){
        //cout<<2<<endl;
        ara[i+1][j] = 'x';
        sum += rec(i+1,j);
    }
    if(ara[i][j-1]=='.'){
        //cout<<3<<endl;
        ara[i][j-1] = 'x';
        sum += rec(i,j-1);
    }
    if(ara[i][j+1]=='.'){
        //cout<<4<<endl;
        ara[i][j+1] = 'x';
        sum += rec(i,j+1);
    }
    return sum;
}


int main(){

    int i,j,k,c,t,cas=0,a,b,l,m;
   // freopen("1012.txt","r",stdin);
    cin>>t;
    while(++cas<=t){
        c = 0;
        memset(ara,'x',sizeof(ara));
        scanf("%d %d",&w,&h);

        for(i=0;i<h;i++) scanf("%s",&ara[i]);

        for(i=0;i<h;i++){
            //cout<<i<<endl;
            //cout<<ara[i]<<endl;
            for(j=0;j<w;j++){
                if(ara[i][j] == '@') break;
            }
            if(ara[i][j] == '@') break;
        }
        //cout<<i<<" "<<j<<endl;


        printf("Case %d: %d\n",cas,rec(i,j));
       // fn();
    }
    return 0;
}




/*

bool ch(int j,int n){
    if(n==1){
        if(j<=w) return 1;
        else return 0;
    }
    else{
        if(j>=0) return 1;
        else return 0;
    }
}

int fill_r(int i,int j,int n){
    int c=0,c1=0;
    while(ch(j,n)){
        c1=0;
        if(ara[i][j]=='.'){

            if((j==0&&i==0)&&(ara[i][j+1] == 'r'||ara[i+1][j] == 'r')) c1 = 1;
            else if((i==0&&j==w)&&(ara[i+1][j]=='r'||ara[i][j-1]=='r')) c1 = 1;
            else if((i==h&&j==0)&&(ara[i-1][j]=='r'&&ara[i][j+1]=='r')) c1 = 1;
            else if((i==h&&j==w)&&(ara[i-1][j]=='r'&&ara[i][j-1]=='r')) c1 = 1;
            else if(i==0&&(ara[i+1][j]=='r'||ara[i][j-1]=='r'||ara[i][j+1]=='r')) c1 =1;
            else if(i==h&&(ara[i-1][j]=='r'||ara[i][j-1]=='r'||ara[i][j+1]=='r')) c1 = 1;
            else if(j==0&&(ara[i+1][j]=='r'||ara[i-1][j]=='r'||ara[i][j+1]=='r')) c1 = 1;
            else if(j==w&&(ara[i+1][j]=='r'||ara[i-1][j]=='r'||ara[i][j-1]=='r')) c1 = 1;
            else if((ara[i][j-1]=='r'||ara[i][j+1]=='r'||ara[i-1][j]=='r'||ara[i+1][j]=='r')) c1 = 1;

            if(c1 = 1){
                ara[i][j] = 'r';
                c++;
            }
        }
        else break;

        if(n==1) j++;
        else j--;
    }
    return c;
}
*/

/*
for(i=a-1;i>=0;i--){
            for(j=0;j<=w;j++){
                if(ara[i][j] == '.'){
                    if(ara[i+1][j] == 'r'){
                        c++;
                        ara[i][j] == 'r';
                        c+=fill_r(i,j+1,1);
                        c+=fill_r(i,j-1,0);
                    }
                }
            }
        }
        for(i=a+1;i<=h;i++){
            for(j=0;j<=w;j++){
                if(ara[i][j] == '.'){
                    if(ara[i-1][j] == 'r'){
                        c++;
                        ara[i][j] == 'r';
                        c+=fill_r(i,j+1,1);
                        c+=fill_r(i,j-1,0);
                    }
                }
            }
        }
*/
