#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
void display (vector<vector<int> > * array);
int main()
{	
	int rows,columns=1;
	int TestCases;
	queue<int> queue;
	string stream;
	vector<pair<int,int> > sources;
	scanf("%d",&TestCases);
	for (int i=0;i<TestCases;i++)
	{
		scanf("%d %d",&rows,&columns);
		vector<vector<int> > array(rows,vector<int>(columns));
		for(int j=0;j<rows;j++)
		{
			cin>>stream;
			for(int k=0;k<columns;k++)
			{
				array[j][k] = (stream[k] == '1' )? 0 : -1;
				if (array[j][k] == 0)
					sources.push_back(make_pair<int,int>(j,k));
			}
		}
		display(&array);
	}

	return 0;
}
void display(vector<vector<int> >*array)
{
	int rows,columns;
	rows = array->size();
	columns = (*array)[0].size();
	for (int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			printf("%d ",(*array)[i][j]);
		}
		printf("\n");
	}
}
