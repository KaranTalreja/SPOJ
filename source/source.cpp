#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void freeGraph();
void decompileGraph();

class edge;
class node;
class node {

public:
	int Id;
	vector<edge*> edges;
	bool explored;
	node(int Id)
	{
		this->Id = Id;
		explored = false;
	}
	node();
};
class edge
{
public:
	node* first,*second;
	int weight;
	edge()
	{
		first = NULL;
		second = NULL;
		weight = 0;
	}
	edge(node *first,node* second,int weight)
	{
		this->first = first;
		this->second = second;
		this->weight = weight;
	}
};
int noOfNodes,noOfEdges;
vector<node*> *Graph;
vector<edge*> AllEdges;
int main() {
	edge *tempEdge,*tempEdge2;
	node *tempNodeStart,*tempNodeEnd;
	int tempNodeStartVal,tempNodeEndVal,tempWeight;
	scanf("%d %d",&noOfNodes,&noOfEdges);
	Graph = new vector<node*>(noOfNodes);
	for(int i = 0; i<noOfEdges;i++)
	{
		scanf("%d %d %d",&tempNodeStartVal,&tempNodeEndVal,&tempWeight);
		tempNodeStart = (NULL == (*Graph)[tempNodeStartVal-1]) ? new node(tempNodeStartVal) : (*Graph)[tempNodeStartVal-1];
		tempNodeEnd = (NULL == (*Graph)[tempNodeEndVal-1]) ? new node(tempNodeEndVal) : (*Graph)[tempNodeEndVal-1];
		tempEdge = new edge(tempNodeStart,tempNodeEnd,tempWeight);
		tempEdge2 = new edge(tempNodeEnd,tempNodeStart,tempWeight);
		tempNodeStart->edges.push_back(tempEdge);
		tempNodeEnd->edges.push_back(tempEdge2);
		AllEdges.push_back(tempEdge);
		AllEdges.push_back(tempEdge2);
		(*Graph)[tempNodeStartVal-1] = tempNodeStart;
		(*Graph)[tempNodeEndVal-1] = tempNodeEnd;
	}
	int i = noOfNodes,MstCost=0;
	(*Graph)[0]->explored = true;
	i--;
	while(i>0)
	{
		edge* minEdge = AllEdges[0];
		for(int j=0;j<AllEdges.size();j++)
		{
			if(AllEdges[j]->first->explored == true && AllEdges[j]->second->explored == false)
				minEdge = minEdge->weight >= AllEdges[j]->weight ? AllEdges[j] : minEdge;
		}
		MstCost += minEdge->weight;
		i--;
		minEdge->second->explored = true;
	}
	cout<<MstCost<<endl;
	//decompileGraph();
	freeGraph();
	return 0;
}
void freeGraph()
{
	for(int i =0;i<noOfNodes;i++)
	{
		int size = ((*Graph)[i])->edges.size();
		for (int j=0;j<size;j++)
		{
			delete ((*Graph)[i])->edges[j];
		}
		delete  (*Graph)[i];
	}
}
void decompileGraph()
{
	cout<<noOfNodes<<" "<<noOfEdges<<endl;
	for(int i =0;i<noOfNodes;i++)
	{
		int size = ((*Graph)[i])->edges.size();
		for (int j=0;j<size;j++)
		{
			cout<< ((*Graph)[i])->edges[j]->first->Id <<" --> "<< ((*Graph)[i])->edges[j]->second->Id << " : "<<((*Graph)[i])->edges[j]->weight<<endl;
		}

	}
}
