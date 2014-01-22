#include <iostream>
#include <stdio.h>
#include <vector>
class heapMin;
class edge;
class node;
using namespace std;
int computeMst(heapMin *heap,node* currNode);
void freeGraph();
void decompileGraph();
class heapMin
{
	std::vector<edge*> heap;
	int size;
public:
	heapMin()
{
		size = 0;
}
	void insert(edge*);
	edge* extractMin();
	void decompile();
	int getSize()
	{return size;}
	void freeHeap();
};
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
		(*Graph)[tempNodeStartVal-1] = tempNodeStart;
		(*Graph)[tempNodeEndVal-1] = tempNodeEnd;
	}
	heapMin heap;
	int MstCost=0;
	MstCost = computeMst(&heap,(*Graph)[0]);
	cout<<MstCost<<endl;
	//decompileGraph();
	freeGraph();
	return 0;
}
int computeMst(heapMin *heap,node* currNode)
{
	currNode->explored = true;
	for(int j=0;j<currNode->edges.size();j++)
		heap->insert(currNode->edges[j]);
	edge* minEdge = heap->extractMin();
	while(!(minEdge->first->explored == true && minEdge->second->explored == false))
	{
		minEdge = heap->extractMin();
		if(minEdge == NULL)
			return 0;
	}

	return minEdge->weight + computeMst(heap,minEdge->second);
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
void heapMin::insert(edge* Edge)
{
	int parent,child;
	edge* tempEdge;
	heap.push_back(Edge);
	size++;
	child = size;
	parent = (child)/2;
	while((parent >=1) && (heap[parent-1]->weight > heap[child-1]->weight))
	{
		tempEdge = heap[child-1];
		heap[child-1] = heap[parent-1];
		heap[parent-1] = tempEdge;
		child = parent;
		parent = parent/2;
	}

}

edge* heapMin::extractMin(void)
{
	edge* retVal = NULL,*tempEdge;
	if(!heap.empty())
		retVal = heap[0];
	else
		return retVal;
	tempEdge = heap[0];
	heap[0] = heap[size-1];
	heap[size-1] = tempEdge;
	vector<edge*> :: iterator itr = heap.begin();
	itr = itr + size -1;
	heap.erase(itr);
	size--;
	int parent = 1;
	int child = parent;
	while(2*parent <= size)
	{
		if(2*parent != size)
		{
			child = (heap[(2*parent)-1]->weight <= heap[(2*parent)]->weight) ? 2*parent : 2*parent + 1;
			if(heap[child-1]->weight < heap[parent-1]->weight)
			{
				tempEdge = heap[child -1];
				heap[child - 1] = heap[parent - 1];
				heap[parent - 1] = tempEdge;
				parent = child;
			}
			else
				break;
		}
		else
		{
			child = 2*parent;
			if(heap[child-1]->weight < heap[parent-1]->weight)
			{
				tempEdge = heap[child -1];
				heap[child - 1] = heap[parent - 1];
				heap[parent - 1] = tempEdge;
				parent = child;
			}
			else
				break;
		}
	}
	return retVal;
}
void heapMin::decompile()
{
	for(vector<edge*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		cout<<(*itr)->weight<<" ";
	}
	cout<<endl;

}
