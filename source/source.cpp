#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mergesort(int *src,int start,int end,int *original);
void merge(int *src, int bg1, int end1, int bg2, int end2,int *original);
void exchange(int *n1, int *n2);

int main()
{
	int testCases,N;

	cin>>testCases;
	for (int i=0;i<testCases;i++)
	{
		cin>>N;
		int *arrM = (int*)malloc(N*sizeof(int));
		int *originalM = (int*)malloc(N*sizeof(int));
		int *arrF = (int*)malloc(N*sizeof(int));
		int *originalF = (int*)malloc(N*sizeof(int));
		for(int k=0;k<N;k++)
		{
			cin>>arrM[k];
			originalM[k]=arrM[k];
		}
		for(int k=0;k<N;k++)
		{
			cin>>arrF[k];
			originalF[k]=arrF[k];
		}
		mergesort(arrM,0,N-1,originalM);
		mergesort(arrF,0,N-1,originalF);
		int sum=0;
		for(int i=0;i<N;i++)
		{
			sum += (arrM[i]) * (arrF[i]);
		}
		cout<<sum<<endl;
		free(arrM);
		free(arrF);
		free(originalF);
		free(originalM);
	}
	return 0;
}
void exchange(int *n1, int *n2)
{
	int temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}

void merge(int *src, int bg1, int end1, int bg2, int end2,int *original)
{
	int i,j;
	i=bg1;
	j=bg2;
	for(int k=bg1;k<=end2;)
	{
		if(*(src+i)<=*(src+j))
		{
			*(original+k++)=*(src+i++);
		}
		else if(*(src+j)<*(src+i))
		{
			*(original+k++)=*(src+j++);
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
	for(int k=bg1;k<=end2;k++)
	{
		*(src+k)=*(original+k);
	}
}
void mergesort(int *src,int start,int end,int *original)
{
	if(end-start==1)
	{
		if(*(src+start)>*(src+end))
		{
			exchange(src+start,src+end);
			exchange(original+start,original+end);
			return;
		}

	}
	else if(start==end)
	{
		return;
	}
	else
	{
		mergesort(src,start,(start+end)/2,original);
		mergesort(src,((start+end)/2)+1,end,original);
		merge(src,start,(start+end)/2,((start+end)/2)+1,end,original);
	}
}
