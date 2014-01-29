#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void exchange(long long *n1,long long *n2)
{
	long long temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}

long long split_inv_merge(long long *src,long long bg1,long long end1,long long bg2,long long end2,long long *original)
{
	long long i,j,count=0;
	i=bg1;
	j=bg2;
	for(long long k=bg1;k<=end2;)
	{
		if(*(src+i)<=*(src+j))
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
	for(long long k=bg1;k<=end2;k++)
	{
		*(src+k)=*(original+k);
	}
	return count;
}

void mergesort(long long *src,long long start,long long end,long long *original,long long *number_inv)
{
//	static long int number_inv=0;
	if(end-start==1)
	{
		if(*(src+start)>*(src+end))
		{
			exchange(src+start,src+end);
			exchange(original+start,original+end);
			(*number_inv)++;
			return;
		}

	}
	else if(start==end)
	{
		return;
	}
	else
	{
		mergesort(src,start,(start+end)/2,original,number_inv);
		mergesort(src,((start+end)/2)+1,end,original,number_inv);
		(*number_inv)+=split_inv_merge(src,start,(start+end)/2,((start+end)/2)+1,end,original);
		return;
	}
}
int main()
{	
	int TestCases,N;
	cin>>TestCases;
//	cout<<TestCases<<" ";
	char temp;
	long long* arr2,*original2;
	long long inversions=0;
	for(int j=0;j<TestCases;j++)
	{
		inversions=0;
		cin>>N;
		//cout<<N<<" N "<<endl ;
		arr2 = (long long*)malloc(N*sizeof(long long));
		original2 = (long long*)malloc(N*sizeof(long long));
		for(int i=0;i<N;i++)
		{
		cin>>arr2[i];
//		cout<<arr2[i]<<endl;;
		original2[i]=arr2[i];
		}
		mergesort(arr2,0,N-1,original2,&inversions);
		cout<<inversions<<endl;
		free (arr2);
		free(original2);
		//cin>>temp;
		//cout<<"worf"<<temp<<endl;
	}

	return 0;
}
