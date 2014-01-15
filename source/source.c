
#include <stdio.h>
int main()
{	
	int TestCases,Generation;
	long long NoOfChild;
	int j;
	int count=0;
	long long parent;
	scanf("%d",&TestCases);
	for(j=0;j<TestCases;j++)
	{
		scanf("%d %llu",&Generation,&NoOfChild);
		NoOfChild = ((0x00 | 0x01) << (Generation-1)) + NoOfChild -1;
		//printf("temp->%llu \n no%llu\n",);
		count =0;
		while(Generation != 1)
		{
			parent = NoOfChild/2;
			count += (NoOfChild - (parent*2));
			NoOfChild = parent;
			Generation--;
		}
		((count & 0x01) == 1) ? printf("Female\n") : printf("Male\n");
		/*for( i=0;i<N;i++)
		{
		}*/
	}

	return 0;
}
