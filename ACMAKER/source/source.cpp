#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tr1/unordered_map>
#include <string.h>
using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n );//fast input function
inline int getInt(char **str);
inline void inpLine(char* str);

int main()
{
	vector<char*> listOfWords;
	listOfWords.push_back("THIS");
	listOfWords.push_back("BOOK");
	listOfWords.push_back("GOOD");
	char* Acronym = "HOOD";
	size_t lenOfAcr = strlen(Acronym);
	vector<vector<vector<int> > > Cache;
	for(size_t i=0;i<=lenOfAcr;i++)
	{
		vector<vector<int> >tmp;
		tmp.push_back(vector<int> (1));
		for(size_t j=0;j<listOfWords.size();j++)
		{
			size_t tmpLen = strlen(listOfWords[j]);
			vector<int> tmpVec(tmpLen+1);
			tmp.push_back(tmpVec);
		}
		Cache.push_back(tmp);
	}

	for(size_t i=1;i<Cache.size();i++)
	{
		for(size_t j=1;j<Cache[i].size();j++)
		{
			for(size_t k=1;k<Cache[i][j].size();k++)
			{
				if(i == 1 && j == 1)
				{
					if(Acronym[i-1] == listOfWords[j-1][k-1])
					{
						Cache[i][j][k] = 1;
					}
					else
					{
						Cache[i][j][k] = Cache[i][j][k-1];
					}
				}
				else
				{
					if(Acronym[i-1] == listOfWords[j-1][k-1])
					{
						Cache[i][j][k] = Cache[i-1][j][k-1] || Cache[i-1][j-1].back();
					}
					else
					{
						Cache[i][j][k] = Cache[i][j][k-1];
					}
				}
			}
		}
	}



	for(size_t i=0;i<Cache.size();i++)
	{
		cout<<"I == "<<i<<endl;
		for(size_t j=0;j<Cache[i].size();j++)
		{
			for(size_t k=0;k<Cache[i][j].size();k++)
			{

				cout<<Cache[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	cout<<"!! "<<Cache[4][3].back()<<endl;
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
	while (c != '\n' && c != ' ') {
		str[i] = c;
		c = getcx();
		i = i + 1;
	}
	str[i] = '\0';
}
