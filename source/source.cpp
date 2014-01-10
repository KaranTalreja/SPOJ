#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        int temp;
        cin>>temp;
        if(temp!=42)
            cout<<temp<<endl;
        else
            return 0;
    }
}

