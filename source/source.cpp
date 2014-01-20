#include <iostream>
#include <stdio.h>
#include <tr1/unordered_map>
using namespace std;
long int getValue(long int n,tr1::unordered_map<long int,long int>*Cache);
int main()
{	
	long int n=0;
	tr1::unordered_map<long int,long int>Cache;
	for(int i=0;i<12;i++)
	{
		(Cache).insert(tr1::unordered_map<long int,long int>::value_type(i,i));
	}
	while(!feof(stdin))
	{
		scanf("%ld",&n);
		printf("%ld\n",getValue(n,&Cache));
	}
	return 0;
}
long int getValue(long int n,tr1::unordered_map<long int,long int>*Cache)
{
	long int retVal;
	tr1::unordered_map<long int,long int>::iterator itr = (*Cache).find(n);
	if(itr!=(*Cache).end())
	{
		retVal =  (itr)->second;
		return retVal;
	}
	else
	{
		long int a,b,c;
		a = getValue(n/4,Cache);
		b = getValue(n/3,Cache);
		c = getValue(n/2,Cache);
		retVal = a+b+c;
	}
	(*Cache).insert(tr1::unordered_map<long int,long int>::value_type(n,retVal));
	return retVal;
}
