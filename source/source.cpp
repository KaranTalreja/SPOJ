#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int testCases,N;

	cin>>testCases;
	for (int i=0;i<testCases;i++)
	{
		cin>>N;
		vector<int> maleScore(N);
		vector<int> femaleScore(N);
		for(int k=0;k<N;k++)
		{
			cin>>maleScore[k];
		}
		for(int k=0;k<N;k++)
		{
			cin>>femaleScore[k];
		}
		sort(maleScore.begin(),maleScore.end(),less<int>());
		sort(femaleScore.begin(),femaleScore.end(),less<int>());
		vector<int>::iterator maleIter=maleScore.begin();
		int sum=0;
		for(vector<int>::iterator femaleIter=femaleScore.begin();femaleIter!=femaleScore.end();++femaleIter,++maleIter)
		{
			sum += (*femaleIter) * (*maleIter);
		}
		cout<<sum<<endl;
	}
	return 0;
}

