#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int array[100000] = {0};
int main()
{
	int TestCases,At,Bt;
	scanf("%d",&TestCases);
	for (int i=0;i<TestCases;i++)
	{
		scanf("%d %d",&At,&Bt);
		pair<int,int> BestVal(0,0);
		for(int j=0;j<At;j++)
		{
			scanf("%d",&array[j]);
		}
		for(int j=0;j<At;j++)
		{
			int sum = 0,k;
			for(k=0; j+k <At; k++)
			{
				if(sum + array[j+k] <= Bt)
					sum += array[j+k];
				else
					break;
			}
			if(BestVal.first < sum && BestVal.second <= k)
			{
				BestVal.first = sum;
				BestVal.second = k;
			}
		}
		printf("%d %d\n",BestVal.first,BestVal.second);
	}
	return 0;
}
