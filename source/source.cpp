#include <stdio.h>
int main()
{
	int boys,girls,larger,smaller;
	int quo;
	scanf("%d %d",&girls,&boys);
	while(-1 != boys && -1 != girls)
	{
		if(girls >= boys)
		{
			 larger = girls;smaller=boys;
		}
		else
		{
			smaller=girls;larger=boys;
		}
		quo = larger / (smaller+1);
		printf("%d\n", (larger - quo*(smaller+1) != 0) ? quo+1 : quo );
		scanf("%d %d",&girls,&boys);
	}
	return 0;
}
