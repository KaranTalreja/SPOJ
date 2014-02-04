#include <stdio.h>
int main()
{	
	int TestCases,N,i,j;
	int currentValue;
	int flag = 0;
	scanf("%d",&TestCases);
	for(i=0;i<TestCases;i++)
	{
		scanf("%d",&N);
		flag=0;
		for (j=0;j<N;j++)
		{
			scanf("%d",&currentValue);
			if(currentValue > j)
				flag = 1;
		}
		(flag==1 )? printf("NO\n"):printf("YES\n");
	}
	return 0;
}
