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
	scanf("%d",&TestCases);
	for (int i=0;i<TestCases;i++)
	{
		scanf("%d %d",&rows,&columns);
		vector<vector<pair<int,bool> > > array(rows,vector<pair<int,bool > >(columns));
		vector<pair<int,int> > queue;
		for(int j=0;j<rows;j++)
		{
			cin>>stream;
			for(int k=0;k<columns;k++)
			{
				if(stream[k] == '1' )
				{
					array[j][k].first = 0;
					array[j][k].second = true;
				}
				else
				{
					array[j][k].first = -1;
					array[j][k].second = false;
				}
				if (array[j][k].first == 0)
					{
					J=j;
					K=k;
					}
			}
		}
		int rowX,columnY;
		int rowX2,columnY2;
		int sizeOfMoves = moves.size();
		queue.push_back(make_pair<int,int>(J,K));
		while(queue.size() > 0)
		{
			int G;
			pair<int,int> value;
			value = queue[queue.size()-1];
			queue.pop_back();
			rowX = value.first;
			columnY = value.second;
			G = array[rowX][columnY].first;
			if(G==0)
				array[rowX][columnY].first = -2;
			for(int k=0;k<sizeOfMoves;k++)
			{
				if(G==-2)
					break;
				rowX2 = rowX + moves[k].first;
				columnY2 = columnY + moves[k].second;
				if(rowX2 >=0 && rowX2<rows && columnY2 >=0 && columnY2 < columns)
				{

					if(array[rowX2][columnY2].second == false  || (array[rowX2][columnY2].second == true && array[rowX2][columnY2].first == 0))
					{
						queue.push_back(make_pair<int,int>(rowX2,columnY2));
						if((array[rowX2][columnY2].first == -1 || G + 1 < array[rowX2][columnY2].first))
							array[rowX2][columnY2].first = G + 1;
						array[rowX2][columnY2].second = true;

					}
					else if(array[rowX2][columnY2].second == true && (array[rowX2][columnY2].first == -1 || G + 1 < array[rowX2][columnY2].first))
					{
						queue.push_back(make_pair<int,int>(rowX2,columnY2));
						array[rowX2][columnY2].first = G + 1;
					}
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
			printf("%d",(*array)[i][j].first == -2 ? 0 : (*array)[i][j].first);
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
