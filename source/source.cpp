#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
string stream;
int getDepth(char a,int Idx,bool flagToClear);
int main() {
	int TestCases,depth;
	scanf("%d",&TestCases);
	for(int i=0;i<TestCases;i++)
	{
		cin>>stream;
		depth = getDepth(stream[0],0,true);
		cout<<depth<<endl;
	}
	return 0;
}
int getDepth(char a,int Idx,bool flagToClear)
{
	static int rightIdx = 0;
	if(flagToClear == true)
		rightIdx = 0;
	int Ld,Rd;
	rightIdx++;
	if(a == 'l')
		return 0;
	Ld = getDepth(stream[Idx+1],Idx+1,false);
	Rd = getDepth(stream[rightIdx],rightIdx,false);
	return Rd > Ld ? (Rd + 1) : (Ld + 1);
}
