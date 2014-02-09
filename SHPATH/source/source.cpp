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
class node;
class heapMin;
class edge;
void decompileGraph(vector<node*> *Graph);
class heapMin
{
	std::vector<node*> heap;
	int size;
public:
	heapMin()
{
		size = 0;
}
	void insert(node*);
	node* extractMin();
	void deleteNode(node*);
	void decompile();
	int getSize()
	{return size;}
	void clearHeap();
};
class node {

public:
	unsigned int data;
	unsigned int Id;
	int indexInHeap;
	bool explored;
	string name;
	vector<edge*> edges;
	node(int data,int Id,string name)
	{
		this->data = data;
		this->Id = Id;
		indexInHeap = -1;
		explored = false;
		this->name = name;
	}
	node();
};
class edge
{
public:
	node* first;
	node* second;
	unsigned int   weight;
	edge();
	edge(node* first,node* second, unsigned int weight)
	{
		this->first = first;
		this->second = second;
		this->weight = weight;
	}

};
int main()
{
	vector<node*> *Graph;
	node* tempNodeStart,*tempNodeEnd;
	edge* tempEdge;
	char line[100];
	char* name = line;
	int TestCases;
	inp(TestCases);
	//string name;
	for(int t=0;t<TestCases;t++)
	{
		int noOfNodes,noOfEdges;
		inp(noOfNodes);
		Graph = new vector<node*>(noOfNodes);
		tr1::unordered_map<string,int> setOfNodes;
		for(int i=1;i<=noOfNodes;i++)
		{
			//cin>>name;
			inpLine(name);
			int tempNodeStartVal,tempNodeEndVal,weight;
			setOfNodes.insert(tr1::unordered_map<string,int>::value_type(name,i));
			tempNodeStartVal = i;
			tempNodeStart = (NULL == (*Graph)[tempNodeStartVal-1]) ? new node(10000000,tempNodeStartVal-1,name) : (*Graph)[tempNodeStartVal-1];
			inp(noOfEdges);
			for(int e=0;e<noOfEdges;e++)
			{
				inp(tempNodeEndVal);
				inp(weight);
				tempNodeEnd = (NULL == (*Graph)[tempNodeEndVal-1]) ? new node(10000000,tempNodeEndVal-1,name) : (*Graph)[tempNodeEndVal-1];
				tempEdge = new edge(tempNodeStart,tempNodeEnd,weight);
				tempNodeStart->edges.push_back(tempEdge);
				(*Graph)[tempNodeEndVal-1] = tempNodeEnd;
			}
			(*Graph)[tempNodeStartVal-1] = tempNodeStart;
		}
		int noOfQueries;
		inp(noOfQueries);
		char* source,*destination;
		//string source,destination;
		tr1::unordered_map<string,int>::iterator itr;
		for(int i=0;i<noOfQueries;i++)
		{
			source = line;
			inpLine(source);
			itr = setOfNodes.find(source);
			destination = line;
			inpLine(destination);
			node* Source,*Destination;
			if(itr!=setOfNodes.end())
				Source = (*Graph)[itr->second-1];
			else
				break;
			itr = setOfNodes.find(destination);
			if(itr!=setOfNodes.end())
				Destination = (*Graph)[itr->second-1];
			else
				break;
			heapMin heap;
			Source->data = 0;
			Source->explored = true;
			vector<edge*>::iterator iter;
			while(Destination->explored == false)
			{
				if(heap.getSize() > 0)
				{
					Source = heap.extractMin();
					heap.deleteNode(Source);
				}
				if(NULL != Source)
				{
					iter = Source->edges.begin();
					for(;iter!=Source->edges.end();++iter)
					{
						tempEdge = (*iter);
						tempNodeEnd = tempEdge->second;
						if((tempNodeEnd->explored == false) && (Source->data + tempEdge->weight < tempNodeEnd->data))
						{
							if(tempNodeEnd -> indexInHeap >= 0)
								heap.deleteNode(tempNodeEnd);
							tempNodeEnd->data = Source->data + tempEdge->weight;
							heap.insert(tempNodeEnd);
						}
					}
					Source->explored = true;
					Source = NULL;
				}
				else
					break;
			}
			cout<<Destination->data<<endl;
			int NoOfNodes = (*Graph).size();
			for(int i =0;i<NoOfNodes;i++)
			{
				((*Graph)[i])->explored = false;
				((*Graph)[i])->data = 10000000;
			}
			heap.clearHeap();

		}
		int NoOfNodes = (*Graph).size();
		for(int i =0;i<NoOfNodes;i++)
		{
			int size = ((*Graph)[i])->edges.size();
			for (int j=0;j<size;j++)
				delete ((*Graph)[i])->edges[j];
			delete ((*Graph)[i]);
		}
		delete Graph;
	}
	//	decompileGraph(Graph);



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

void heapMin::insert(node* Edge)
{
	int parent,child;
	node* tempEdge;
	heap.push_back(Edge);
	Edge->indexInHeap = size;
	size++;
	child = size;
	parent = (child)/2;
	while((parent >=1) && (heap[parent-1]->data > heap[child-1]->data))
	{
		tempEdge = heap[child-1];
		heap[child-1] = heap[parent-1];
		heap[child-1]->indexInHeap = child - 1;
		heap[parent-1] = tempEdge;
		heap[parent-1]->indexInHeap = parent - 1;
		child = parent;
		parent = parent/2;
	}

}

node* heapMin::extractMin(void)
{
	if(!heap.empty())
		return heap[0];
	else
		return NULL;
}
void heapMin::deleteNode(node* del)
{
	node* tempEdge;
	int temp = del->indexInHeap + 1;
	int parent = del->indexInHeap + 1;
	tempEdge = heap[del->indexInHeap];
	heap[del->indexInHeap] = heap[size-1];
	heap[del->indexInHeap]->indexInHeap = del->indexInHeap;
	heap[size-1] = tempEdge;
	heap[size-1]->indexInHeap = size-1;
	vector<node*> :: iterator itr = heap.begin();
	itr = itr + size -1;
	size--;
	int child = temp;
	parent = (child)/2;
	while((parent >=1) && (heap[parent-1]->data > heap[child-1]->data))
	{
		tempEdge = heap[child-1];
		heap[child-1] = heap[parent-1];
		heap[child-1]->indexInHeap = child - 1;
		heap[parent-1] = tempEdge;
		heap[parent-1]->indexInHeap = parent - 1;
		child = parent;
		parent = parent/2;
	}
	child = temp;
	parent = temp;
	while(2*parent <= size)
	{
		if(2*parent != size)
		{
			child = (heap[(2*parent)-1]->data <= heap[(2*parent)]->data) ? 2*parent : 2*parent + 1;
			if(heap[child-1]->data < heap[parent-1]->data)
			{
				tempEdge = heap[child -1];
				heap[child - 1] = heap[parent - 1];
				heap[child-1]->indexInHeap = child-1;
				heap[parent - 1] = tempEdge;
				heap[parent-1]->indexInHeap = parent-1;
				parent = child;
			}
			else
				break;
		}
		else
		{
			child = 2*parent;
			if(heap[child-1]->data < heap[parent-1]->data)
			{
				tempEdge = heap[child -1];
				heap[child - 1] = heap[parent - 1];
				heap[child-1]->indexInHeap = child-1;
				heap[parent - 1] = tempEdge;
				heap[parent-1]->indexInHeap = parent-1;
				parent = child;
			}
			else
				break;
		}
	}
	(*itr)->indexInHeap = -1;
	heap.erase(itr);
}
void heapMin::decompile()
{
	for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		cout<<(*itr)->data<<" ";
	}
	cout<<endl;
	for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		cout<<(*itr)->indexInHeap<<" ";
	}
	cout<<endl;

}
void heapMin::clearHeap()
{
	for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		(*itr)->indexInHeap = -1;
	}
	heap.clear();
}
void decompileGraph(vector<node*> *Graph)
{
	int noOfNodes = (*Graph).size();
	for(int i =0;i<noOfNodes;i++)
	{
		int size = ((*Graph)[i])->edges.size();
		for (int j=0;j<size;j++)
		{
			cout<< ((*Graph)[i])->edges[j]->first->Id + 1 <<" --> "<< ((*Graph)[i])->edges[j]->second->Id +1<< " : "<<((*Graph)[i])->edges[j]->weight<<endl;
		}

	}
}
