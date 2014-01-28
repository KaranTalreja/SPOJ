#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   register int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
using namespace std;
int array[100001] = {0};
int main()
{
	int TestCases,At,Bt;
	scanf("%d",&TestCases);
	for (int i=0;i<TestCases;i++)
	{
		scanf("%d %d",&At,&Bt);
		//int *array = (int*)malloc(sizeof(int)*At);
		pair<int,int> BestVal(0,0);
		for(int j=0;j<At;j++)
		{
			inp(array[j]);
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
		//free(array);
		//array = NULL;
		printf("%d %d\n",BestVal.first,BestVal.second);
	}
	return 0;
}
