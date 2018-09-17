#include<iostream>
#include<stack>
#include<cstdio>


using namespace std;

int main(){

    stack<string> fstk,bstk;

    int t,cas = 0,i,c;
    string cm,url = "http://www.lightoj.com/";
    //freopen("1113.txt","r",stdin);
    cin>>t;
    while(++cas <= t){

        c = 0;
        cout<<"Case "<<cas<<":"<<endl;
        for(;;){

            cin>>cm;
            if(cm == "VISIT"){

                bstk.push(url);
                cin>>url;
                cout<<url<<endl;
                while(!fstk.empty()){

                    fstk.pop();
                }
            }
            else if(cm == "BACK"){

                if(bstk.empty()) cout<<"Ignored"<<endl;
                else{

                    fstk.push(url);
                    url = bstk.top();
                    bstk.pop();
                    cout<<url<<endl;
                }
            }
            else if(cm =="FORWARD"){

                if(fstk.empty()) cout<<"Ignored"<<endl;
                else{

                    bstk.push(url);
                    url = fstk.top();
                    fstk.pop();
                    cout<<url<<endl;
                }
            }
            else if(cm == "QUIT") break;
        }
        url = "http://www.lightoj.com/";
        while(!fstk.empty()){

            fstk.pop();
        }
        while(!bstk.empty()){

            bstk.pop();
        }
    }
    return 0;
}
