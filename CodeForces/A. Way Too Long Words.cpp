#include<iostream>
#include<string>

using namespace std;

int main()
{
    int a,t,i,j;
    std::string str[110];
    std::cin>>t;
    for(i=1;i<=t;i++)
    {
        std::cin>>str;
        a = str.length();

        if(a>10)std::cout<<str[0]<<a-2<<str[a-1];
        else std::cout<<str;

        std::str.clear();
    }
    return 0;
}
