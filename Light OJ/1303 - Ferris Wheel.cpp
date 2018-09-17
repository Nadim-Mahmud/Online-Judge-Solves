#include<bits/stdc++.h>
#define map map<int,bool>
#define pii pair<int,map>
#define piix pair<int,pii>
using namespace std;

int main()
{
    int cas=0,ts,i,j,k,l,n,m,sum,mr,mult,mc=0;
    freopen("1303.txt","r",stdin);
    cin>>ts;
    while(++cas<=ts)
    {
        map mp;
        pii pr2,tmp;
        piix pr1;
        pr2 = pii(-1,mp);
        queue<piix>q1;
        queue<pii>q2;
        stack<pii>st;
        sum = 0,mc=0;

        scanf("%d %d",&n,&m);

        for(i=1;i<=m;i++) q1.push(piix(i,pr2));
        for(i=1;i<=n;i++) q2.push(pii(i,mp));
        //mult=13;
        while(mc<n)
        {
            sum += 5;
            mr = 0;
            pr1 = q1.front();
            pr2 = pr1.second;
            cout<<"out: "<<sum<<" "<<pr1.first<<" "<<pr2.first<<endl;
            if(mp.size() != m&&pr2.first!=-1) q2.push(pr2);
            if(!q2.empty()){
                //cout<<"ues\n";
                for(i=0;i<n;i++){
                    pr2 = q2.front();
                  //  cout<<pr2.first<<endl;
                    if(pr2.second[pr1.first] == 0){
                        cout<<pr1.first<<"aa\n";
                        pr2.second[pr1.first] = 1;
                        q1.push(piix(pr1.first,pr2));
                        q2.pop();
                        mr=1;
                        break;
                    }
                    else{
                        if(pr2.second.size() != m) st.push(pr2);
                        else mc++,cout<<mc<<endl;
                        q2.pop();
                    }
                }
                while(!st.empty()){
                    //cout<<"ssssttt\n";
                    pr2 = st.top();
                    st.pop();
                    q2.push(pr2);
                }
            }
            //cout<<mr<<endl;
            if(!mr){
                //cout<<mr<<endl;
                map mp1;
                pr1 = piix(pr1.first,pii(-1,mp1));
                q1.push(pr1);
            }
            q1.pop();
            pr1=q1.front();
            cout<<"in : "<<pr1.first<<"  "<<pr1.second.first<<endl;
        }
        printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
