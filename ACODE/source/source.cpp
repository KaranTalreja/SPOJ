#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n );//fast input function
inline int getInt(char **str);
inline void inpLine(char* str);
int count[5001];
int main()
{
	char *buffer = (char*)malloc(5000*sizeof(char));
	while(1)
	{
		inpLine(buffer);
		if(buffer[0] == '0')
			break;

		size_t strLen = strlen(buffer);
		count[0] = 1;
		count[1] = 1;
		int tempNumber;
		for(size_t i = 2; i <= strLen; i++)
		{
			tempNumber = (buffer[i-2]-48) * 10 + (buffer[i-1] - 48);
			if(tempNumber == 0)	//Case "00"
			{
				count[strLen] = 0;
				break;
			}
			else if(buffer[i-2] == '0') // Case "0." .:=[1-9]
				count[i] = count[i-1];
			else if (tempNumber == 10 || tempNumber == 20) // Case "10" or "20"
				count[i] = count [i-2];
			else if(tempNumber <= 26 && (tempNumber != 10 && tempNumber != 20 )) //Case [11,26] - {20}
				count[i] = count[i-1] + count[i-2];
			else
				count[i] = count[i-1];
		}
		printf("%d\n",count[strLen]);
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
