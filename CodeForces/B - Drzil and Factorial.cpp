#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int i,j,n,x;//ara2[1] ={2},ara3[1]={3},ara4[2]={3,2,2},ara5[1]=5,ara6[2]={5,3},ara7[1]={7},ara8[4]={2,2,2,7},ara9[4]={3,3,2,7};

    char ara[1000];

    vector<int> vc;

    cin>>n;
    cin>>ara;

    for(i=0;i<n;i++){

        x = ara[i] - '0';

        if(x == 1||x == 0) continue;
        else if(x == 2) vc.push_back(2);
        else if(x == 3) vc.push_back(3);
        else if(x == 4){
            vc.push_back(2);
            vc.push_back(2);
            vc.push_back(3);
        }
        else if(x == 5) vc.push_back(5);
        else if(x == 6){
            vc.push_back(5);
            vc.push_back(3);
        }
        else if(x == 7) vc.push_back(7);
        else if(x == 8){
            vc.push_back(2);
            vc.push_back(2);
            vc.push_back(2);
            vc.push_back(7);
        }
        else if(x == 9){
            vc.push_back(3);
            vc.push_back(2);
            vc.push_back(3);
            vc.push_back(7);
        }
    }

    sort(vc.begin(),vc.end());
    reverse(vc.begin(),vc.end());

    x = vc.size();


    for(i=0;i<x;i++){
        cout<<vc[i];
    }
    cout<<endl;


    return 0;
}
