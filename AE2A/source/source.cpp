#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n );//fast input function
inline int getInt(char **str);
inline void inpLine(char* str);
int count[5001];
int main()
{
	int testCases,n,k;
	inp(testCases);
	for(int i =0;i< testCases;i++)
	{
		inp(n);
		inp(k);
		vector<vector<int> > Cache(n , vector<int>(k+1));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=k ;j++)
			{
				if(j>0 && j<=6)
					Cache[i][j] = 1;
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=k ;j++)
			{
				if( j > 1)
					Cache[i][j] += Cache[i-1][j-1];
				if( j > 2)
					Cache[i][j] += Cache[i-1][j-2];
				if( j > 3)
					Cache[i][j] += Cache[i-1][j-3];
				if( j > 4)
					Cache[i][j] += Cache[i-1][j-4];
				if( j > 5)
					Cache[i][j] += Cache[i-1][j-5];
				if( j > 6)
					Cache[i][j] += Cache[i-1][j-6];


			}
		}
		cout<<Cache[n-1][k]<<endl;
	}
	return 0;
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
