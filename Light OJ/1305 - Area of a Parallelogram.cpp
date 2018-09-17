#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define eps 0.00000001

int main(){

    int x1,x2,x3,x4,y1,y2,y3,y4,t,i,ab;
    //float a,b,c,s,area;

    //freopen("area.txt","r",stdin);

    cin>>t;

    for(i=1;i<=t;i++){

        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

        x4 = x1 + x3 - x2;
        y4 = y1 + y3 - y2;

        /*a = sqrt((x2-x1)*(x2-x1) + (y2 - y1)*(y2-y1));
        b = sqrt((x4-x1)*(x4-x1) + (y4 - y1)*(y4-y1));
        c = sqrt((x4-x2)*(x4-x2) + (y4 - y2)*(y4-y2));

        s = (a+b+c)/2.0;

        area = s*(s-a)*(s-b)*(s-c);

        area = 2*sqrt(area) + eps;

        ab = (int) area;*/

        ab = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);

        ab = abs(ab);

        printf("Case %d: %d %d %d\n",i,x4,y4,ab);

    }

    return 0;
}

