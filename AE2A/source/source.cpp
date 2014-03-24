#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n );//fast input function
inline int getInt(char **str);
inline void inpLine(char* str);
float Solve(int n,int k);
unsigned long long kMax = 1000000;
tr1::unordered_map<unsigned long long,float> Cache;
tr1::unordered_map<unsigned long long, float>::iterator CacheItr;
pair<unsigned long long,float> tmpPair;
int main()
{
	int testCases,n,k;
	inp(testCases);
	for(int i =0;i< testCases;i++)
	{
		//		Cache.clear();
		inp(n);
		inp(k);
		//kMax = k;
		int i = 1;
		for(int j=1;j<=6 ;j++)
		{
			unsigned long long key = ((unsigned long long)i * kMax) + (unsigned long long)j;
			tmpPair.first =key;
			tmpPair.second = 1.0/6.0;
			Cache.insert(tmpPair);
		}
		cout << (unsigned int)(Solve(n,k) * 100.0)/* <<"\t "<< n<< " : "<<k*/<<endl;
	}

	return 0;
}

float Solve(int i,int j)
{
	float retVal = 0;
	unsigned long long key = ((unsigned long long )i * kMax) + (unsigned long long )j;
	if(j < 1 || i > j || j > 6*i)
		return 0;
	else
	{
		CacheItr = Cache.find(key);
		if(Cache.end() != CacheItr)
			return CacheItr->second;
		else
		{
			if( j > 6)
				retVal += (Solve(i-1,j-6) + Solve(i-1,j-5) + Solve(i-1,j-4) + Solve(i-1,j-3) + Solve(i-1,j-2) + Solve(i-1,j-1)) * 1/6;
			else if( j > 5)
				retVal += (Solve(i-1,j-5) + Solve(i-1,j-4) + Solve(i-1,j-3) + Solve(i-1,j-2) + Solve(i-1,j-1)) * 1/6;
			else if( j > 4)
				retVal += (Solve(i-1,j-4) + Solve(i-1,j-3) + Solve(i-1,j-2) + Solve(i-1,j-1)) * 1/6;
			else if( j > 3)
				retVal += (Solve(i-1,j-3) + Solve(i-1,j-2) + Solve(i-1,j-1)) * 1/6;
			else if( j > 2)
				retVal += (Solve(i-1,j-2) + Solve(i-1,j-1)) * 1/6;
			else if( j > 1)
				retVal += (Solve(i-1,j-1) * 1/6);
			tmpPair.first =key;
			tmpPair.second = retVal;
			Cache.insert(tmpPair);
		}
	}
	return retVal;
}

inline int getInt(char **str)
{
	char ch = **str;int sign=1;
	int n=0;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=*(++(*str));}
	while(  ch >= '0' && ch <= '9' )
	{n = (n<<3)+(n<<1) + ch-'0'; ch = *(++(*str));}
	return (n*sign);
}
inline void inp( int &n )//fast input function
{
	n=0;
	register int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
inline void inpLine(char *str)
{
	register char c = 0;
	register int i = 0;
	while (c < 33)
		c = getcx();
	while (c != '\n'/* && c != ' '*/) {
		str[i] = c;
		c = getcx();
		i = i + 1;
	}
	str[i] = '\0';
}
