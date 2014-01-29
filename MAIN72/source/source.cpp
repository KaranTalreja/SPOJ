#include <iostream>
#include <stdio.h>
#include <vector>
#include <tr1/unordered_set>
using namespace std;
int main()
{	
	tr1::unordered_set<int>::iterator itr;
	int TestCases,N;
	int array[100];
	scanf("%d",&TestCases);
	for(int i=0;i<TestCases;i++)
	{
		tr1::unordered_set<int> distinctSums;
		vector<int> toBeAdded;
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			scanf("%d",&array[j]);
		for(int j=0;j<N;j++)
		{
			itr = distinctSums.begin();
			for(;itr!=distinctSums.end();++itr)
				toBeAdded.push_back(array[j] + *(itr));
			for(int k=0;k<toBeAdded.size();k++)
				distinctSums.insert(toBeAdded[k]);
			toBeAdded.clear();
			distinctSums.insert(array[j]);
		}
		int sum=0;
		itr = distinctSums.begin();
		for(;itr!=distinctSums.end();++itr)
			sum += *(itr);
		printf("%d\n",sum);
	}
	return 0;
}

