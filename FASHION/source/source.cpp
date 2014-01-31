#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define getcx getchar_unlocked
#define BASE 10
#define MAX 1000
int arrM[MAX],arrF[MAX];
inline void inp( int &n )//fast input function
{
   n=0;
   register int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
void radixsort(int *a, int n);
int main()
{
	int testCases,N;

	inp(testCases);
	for (int i=0;i<testCases;i++)
	{
		inp(N);
		for(int k=0;k<N;k++)
			inp(arrM[k]);
		for(int k=0;k<N;k++)
			inp(arrF[k]);
		radixsort(arrM,N);
		radixsort(arrF,N);
		int sum=0;
		for(int i=0;i<N;i++)
		{
			sum += (arrM[i]) * (arrF[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}

void radixsort(int *a, int n)
{
  int i, b[MAX], m = a[0], exp = 1;
  for (i = 1; i < n; i++)
  {
    if (a[i] > m)
      m = a[i];
  }

  while (m / exp > 0)
  {
    int bucket[BASE] ={  0 };
    for (i = 0; i < n; i++)
      bucket[(a[i] / exp) % BASE]++;
    for (i = 1; i < BASE; i++)
      bucket[i] += bucket[i - 1];
    for (i = n - 1; i >= 0; i--)
      b[--bucket[(a[i] / exp) % BASE]] = a[i];
    for (i = 0; i < n; i++)
      a[i] = b[i];
    exp *= BASE;
  }
}
