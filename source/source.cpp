#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void exchange(long int *n1,long int *n2)
{
	long int temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}

long int split_inv_merge(long int *src,long int bg1,long int end1,long int bg2,long int end2,long int *original)
{
	long int i,j,count=0;
	i=bg1;
	j=bg2;
	for(long int k=bg1;k<=end2;)
	{
		if(*(src+i)<*(src+j))
		{
			*(original+k++)=*(src+i++);
		}
		else if(*(src+j)<*(src+i))
		{
			*(original+k++)=*(src+j++);
			count+=(end1-i+1);
		}
		if(i>end1)
		{
			while(j<=end2)
			{
				*(original+(k++))=*(src+(j++));
			}
		}
		else if(j>end2)
		{
			while(i<=end1)
			{
				*(original+(k++))=*(src+(i++));
			}
		}
	}
	for(long int k=bg1;k<=end2;k++)
	{
		*(src+k)=*(original+k);
	}
	return count;
}

long int* mergesort(long int *src,long int start,long int end,long int *original)
{
	static long int number_inv=0;
	if(end-start==1)
	{
		if(*(src+start)>*(src+end))
		{
			exchange(src+start,src+end);
			exchange(original+start,original+end);
			number_inv++;
			return (&number_inv);
		}

	}
	else if(start==end)
	{
		return(&number_inv);
	}
	else
	{
		mergesort(src,start,(start+end)/2,original);
		mergesort(src,((start+end)/2)+1,end,original);
		number_inv+=split_inv_merge(src,start,(start+end)/2,((start+end)/2)+1,end,original);
		return (&number_inv);
	}
}
int main()
{	
	int TestCases,N;
	cin>>TestCases;
	cout<<TestCases<<" ";
	char temp;
	long int* arr2,*original2;
	long int* numberOfInversions;
	for(int j=0;j<TestCases;j++)
	{
		cin>>N;
		cout<<N<<" " ;
		arr2 = (long int*)malloc(N*sizeof(int));
		original2 = (long int*)malloc(N*sizeof(int));
		for(int i=0;i<N;i++)
		{
		cin>>arr2[i];
		cout<<arr2[i]<<endl;;
		original2[i]=arr2[i];
		}
		numberOfInversions = (mergesort(arr2,0,N-1,original2));
		cout<<*numberOfInversions<<endl;
		free (arr2);
		free(original2);
cin>>temp;
cout<<"worf"<<temp<<endl;
	}

	return 0;
}
