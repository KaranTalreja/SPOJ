#include <stdio.h>
#define MAX 100000
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
int array[MAX];
int MaximumSubArray(int start, int end,int* array);
int MaximumCrossingArray(int start,int mid,int end,int *array);
int main()
{	
	int TestCases, N;
	inp(TestCases);
	for (int i=0;i<TestCases;i++)
	{
		inp(N);
		for(int j=0;j<N;j++)
			inp(array[j]);
		printf("%d\n",MaximumSubArray(0,N-1,array));

	}
	return 0;
}
int MaximumSubArray(int start,int end,int *array)
{
	if(start == end)
		return array[start];
	int retVal,leftArrayMax,rightArrayMax,crossingArrayMax;
	int mid = (start+end)/2;
	leftArrayMax = MaximumSubArray(start,mid,array);
	rightArrayMax = MaximumSubArray(mid+1,end,array);
	crossingArrayMax = MaximumCrossingArray(start,mid,end,array);

	if(rightArrayMax >= leftArrayMax && rightArrayMax >= crossingArrayMax)
		retVal = rightArrayMax;
	else if(leftArrayMax >= rightArrayMax && leftArrayMax >= crossingArrayMax)
		retVal = leftArrayMax;
	else
		retVal = crossingArrayMax;
	return retVal;
}

int MaximumCrossingArray(int start,int mid,int end ,int* array)
{
	int sum=array[mid],tempMid = mid;
	int bestSum,rightSum;
	bestSum = array[mid];
	while(tempMid > start)
	{
		sum += array[tempMid-1];
		tempMid--;
		if(sum >= bestSum)
			bestSum = sum;
	}
	tempMid = mid;
	sum = bestSum;
	rightSum = array[mid];
	while(tempMid < end)
	{
		sum += array[tempMid+1];
		tempMid++;
		if(sum >= rightSum)
			rightSum = sum;
	}
	return rightSum;
}
