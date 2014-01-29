
#include <stdio.h>
int main()
{	
	int TestCases,Generation;
	long long NoOfChild;
	int j;
	int count=0;
	scanf("%d",&TestCases);
	for(j=0;j<TestCases;j++)
	{
		scanf("%d %llu",&Generation,&NoOfChild);
		NoOfChild = NoOfChild -1;
		count =0;
		while(NoOfChild)
		{
			count += (NoOfChild & 0x01);
			NoOfChild = (NoOfChild >> 1);
		}
		((count & 0x01) == 1) ? printf("Female\n") : printf("Male\n");
	}

	return 0;
}
