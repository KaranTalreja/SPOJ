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
		vector<int> first(N);
		vector<int> temp(N);
		vector<int> ::iterator start= first.begin();
		int currentValue;
		bool flag = true;
		for (int j=0;j<N;j++)
		{
			cin>>currentValue;
			temp[j]=currentValue;
			if(currentValue <= j)
			{
					first.insert(start + j - currentValue,j);
					start = first.begin();
			}
			else
			{
				flag = false;
				break;
			}


		}

		vector<int> second(N);

		for(int k=0;k<N;k++)
			second[first[k]] = k+1;


//		for(int k=0;k<N;k++)
//			cout<<second[k]<<" ";
//		cout<<endl;
//		for(int k=0;k<N;k++)
//				cout<<temp[k]<<" ";
//			cout<<endl;
		if(flag==false)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
