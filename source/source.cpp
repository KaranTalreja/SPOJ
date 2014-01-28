#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int TestCases,At,Bt;
	scanf("%d",&TestCases);
	for (int i=0;i<TestCases;i++)
	{
		scanf("%d %d",&At,&Bt);
		int *array = (int*)malloc(sizeof(int)*At);
		pair<int,int> BestVal(0,0);
		for(int j=0;j<At;j++)
		{
			scanf("%d",&array[j]);
		}
		int k=0,sum=0;
		for(int j=0;j<At;j++)
		{
			if(sum)
			{
				sum-=array[j-1];
				if((j+k-1 < At) && (sum + array[j+k-1] <= Bt))
					sum += array[j+k-1];
				else if(j+k-1 < At)
				{
					k--;
					continue;
				}
				else
				{
					break;
				}
			}
			for(;j+k <At; k++)
			{
				if(sum + array[j+k] <= Bt)
					sum += array[j+k];
				else
					break;
			}
			if(BestVal.second < k)
			{
				BestVal.first = sum;
				BestVal.second = k;
			}
			else if(BestVal.second == k && BestVal.first > sum)
			{
				BestVal.first = sum;
				BestVal.second = k;
			}
		}
		free(array);
		array = NULL;
		printf("%d %d\n",BestVal.first,BestVal.second);
	}
	return 0;
}
