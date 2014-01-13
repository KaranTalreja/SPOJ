#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{	
	int TestCases,N;
	cin>>TestCases;
	for(int i=0;i<TestCases;i++)
	{
		cin>>N;
		int currentValue;
		bool flag = true;
		for (int j=0;j<N;j++)
		{
			cin>>currentValue;
			if(currentValue > j)
			{flag = false;
			break;}
		}
		if(flag==false)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
