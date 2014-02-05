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
int main()
{	
	int TestCases, N;
	inp(TestCases);
	for (int i=0;i<TestCases;i++)
	{
		inp(N);
		for(int j=0;j<N;j++)
			inp(array[j]);
		int best = array[0],retVal,leftArrayMax,rightArrayMax,crossingArrayMax,count=1;
		for(int j=1;j<N;j++)
		{
			leftArrayMax = array[j-1];
			rightArrayMax = array[j];
			crossingArrayMax = leftArrayMax + rightArrayMax;
			if(rightArrayMax >= leftArrayMax && rightArrayMax >= crossingArrayMax)
				retVal = array[j];
			else if(leftArrayMax >= rightArrayMax && leftArrayMax >= crossingArrayMax)
				retVal = leftArrayMax + array[j];
			else
				retVal = crossingArrayMax;
			array[j] =  retVal;
			if(retVal > best)
			{
				best = retVal;
				count=1;
			}
			else if(retVal == best)
			{
				if(leftArrayMax == 0 || rightArrayMax == 0)
					count++;
				if(rightArrayMax == best)
					count++;
			}
		}
		printf("%d %d\n",best,count);
	}
	return 0;
}
