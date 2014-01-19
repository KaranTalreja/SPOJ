#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
using namespace std;
void display (vector<vector<pair<int,bool> > > * array);
void displaySources(vector<pair<int,int> > *sources);
int main()
{	
	int rows,columns=1;
	int TestCases;
	string stream;
	vector<pair<int,int> > moves;
	int J,K;
	moves.push_back(make_pair<int,int>(1 , 0)); // row+1 DOWN
	moves.push_back(make_pair<int,int>(-1, 0)); // row-1 UP
	moves.push_back(make_pair<int,int>(0 , 1)); // column+1 RIGHT
	moves.push_back(make_pair<int,int>(0 ,-1)); //column-1 LEFT
	int G;
	pair<int,int> value;
	int rowX,columnY;
	int rowX2,columnY2;
	int sizeOfMoves = moves.size();
	vector<pair<int,int> > queue;
	queue.reserve(1024);
	scanf("%d",&TestCases);
	for (int i=0;i<TestCases;i++)
	{
		scanf("%d %d",&rows,&columns);
		vector<vector<pair<int,bool> > > array(rows,vector<pair<int,bool > >(columns));
		for(int j=0;j<rows;j++)
		{
			cin>>stream;
			for(int k=0;k<columns;k++)
			{
				array[j][k].first = (stream[k] == '1' )  ? 0 :-1;
				array[j][k].second = false;
				if (array[j][k].first == 0)
					queue.push_back(make_pair<int,int>(j,k));
			}
		}
		while(queue.size() > 0)
		{
			value = queue[queue.size()-1];
			queue.pop_back();
			rowX = value.first;
			columnY = value.second;
			array[rowX][columnY].second = true;
			G = array[rowX][columnY].first;
			for(int k=0;k<sizeOfMoves;k++)
			{
				rowX2 = rowX + moves[k].first;
				columnY2 = columnY + moves[k].second;
				if(rowX2 >=0 && rowX2<rows && columnY2 >=0 && columnY2 < columns)
				{

					if((array[rowX2][columnY2].first == -1 || G + 1 < array[rowX2][columnY2].first))
					{
						array[rowX2][columnY2].first = G + 1;
						if(array[rowX2][columnY2].second == true)
							queue.push_back(make_pair<int,int>(rowX2,columnY2));
					}
					if(array[rowX2][columnY2].second == false)
						queue.push_back(make_pair<int,int>(rowX2,columnY2));
				}
			}
			//displaySources(&queue);
			//display(&array);
		}
		display(&array);
	}
	return 0;
}
void display(vector<vector<pair<int,bool> > >*array)
{
	int rows,columns;
	rows = array->size();
	columns = (*array)[0].size();
	for (int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			printf("%d",(*array)[i][j].first);
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
		printf("(%d,%d) ",(*sources)[j].first,(*sources)[j].second);
	}
	printf("\n");
}
