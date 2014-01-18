#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
void display (vector<vector<int> > * array);
void displaySources(vector<pair<int,int> > *sources);
int main()
{	
	int rows,columns=1;
	int TestCases;
	queue<int> queue;
	string stream;
	vector<pair<int,int> > sources;
	vector<pair<int,int> > moves;
	moves.push_back(make_pair<int,int>(1 , 0)); // row+1 DOWN
	moves.push_back(make_pair<int,int>(-1, 0)); // row-1 UP
	moves.push_back(make_pair<int,int>(0 , 1)); // column+1 RIGHT
	moves.push_back(make_pair<int,int>(0 ,-1)); //column-1 LEFT
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
		int rowX,columnY;
		int rowX2,columnY2;
		int sizeOfMoves = moves.size();
		while(sources.size() > 0)
		{
			pair<int,int> value;
			value = sources[sources.size()-1];
			sources.pop_back();
			rowX = value.first;
			columnY = value.second;
			for(int k=0;k<sizeOfMoves;k++)
			{
				rowX2 = rowX + moves[k].first;
				columnY2 = columnY + moves[k].second;
				if(rowX2 >=0 && rowX2<rows && columnY2 >=0 && columnY2 < columns)
				{
					if(array[rowX2][columnY2] == -1)
						sources.push_back(make_pair<int,int>(rowX2,columnY2));
					if(array[rowX2][columnY2] == -1 || array[rowX][columnY] + 1 < array[rowX2][columnY2])
						array[rowX2][columnY2] = array[rowX][columnY] + 1;
				}
			}
		}
		display(&array);
		displaySources(&sources);
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
			printf("%d",(*array)[i][j]);
			(j != columns-1) ? printf(" "):printf("\n");;
		}
	}
}
void displaySources(vector<pair<int,int> > *sources)
{
	int size;
	size = sources->size();
	for(int j=0;j<size;j++)
	{
		printf("(%d,%d)\n",(*sources)[j].first,(*sources)[j].second);
	}
}
