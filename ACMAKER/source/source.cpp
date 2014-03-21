#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
//#include <tr1/unordered_set>
#include <set>
#include <string.h>
using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n );//fast input function
inline int getInt(char **str);
inline void inpLine(char* str);
struct ltstr {
    bool operator() (const char* lhs, const char* rhs) const{
        return strcmp(lhs,rhs) < 0;
    }
};
int main()
{
	vector<char*> listOfWords;
	vector<vector<vector<int> > > Cache;
	vector<vector<vector<int> > > Count;
	char* Acronym;
	set<string> insignificant;
	int noOfInSignificantWords = 0;
	while (1)
	{
		char* temp = (char*)malloc(150*sizeof(char));
		char* back = temp;
		inp(noOfInSignificantWords);
		if(0 == noOfInSignificantWords)
			break;
		insignificant.clear();
		for(int i=0;i<noOfInSignificantWords;i++)
		{
			inpLine(temp);
			insignificant.insert(temp);
		}
		while(1)
		{
			temp = back;
			inpLine(temp);
			if(0 == strcmp(temp,"LAST CASE"))
				break;

			char* pos = strchr(temp,' ');
			*pos = '\0';
			listOfWords.clear();
			Acronym = temp;
			temp = pos + 1;
			bool toBreak =false;
			while(1)
			{
				pos = strchr(temp,' ');
				if(pos)
					*pos = '\0';
				else
					toBreak = true;
				char* word = temp;
				temp = pos + 1;
				if(insignificant.end() == insignificant.find(word))
					listOfWords.push_back(word);
				if(toBreak)
					break;
			}
			size_t lenOfAcr = strlen(Acronym);
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
				Count.push_back(tmp);
			}

			for(size_t i=1;i<Cache.size();i++)
			{
				for(size_t j=1;j<Cache[i].size();j++)
				{
					for(size_t k=1;k<Cache[i][j].size();k++)
					{

						if(i == 1 && j == 1)
						{
							if(Acronym[i-1] + 32 == listOfWords[j-1][k-1])
							{
								Cache[i][j][k] = 1;
								Count[i][j][k] = 1 + Count[i-1][j][k-1] + Count[i-1][j-1].back() + Count[i][j][k-1];
							}
							else
							{
								Cache[i][j][k] = Cache[i][j][k-1];
								Count[i][j][k] = Count[i][j][k-1];
							}
						}
						else
						{
							if(Acronym[i-1] + 32 == listOfWords[j-1][k-1])
							{
								Cache[i][j][k] = Cache[i-1][j][k-1] || Cache[i-1][j-1].back();
								Count[i][j][k] = Count[i-1][j][k-1] + Count[i-1][j-1].back() + Count[i][j][k-1];
							}
							else
							{
								Cache[i][j][k] = Cache[i][j][k-1];
								Count[i][j][k] = Count[i][j][k-1];
							}
						}
					}
				}
			}
			if(Cache.back().back().back())
			{
				printf("%s can be formed in %d ways\n",Acronym,Count.back().back().back());
			}
			else
			{
				printf("%s is not a valid abbreviation\n",Acronym);
			}
			Cache.clear();
			Count.clear();
		}
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
