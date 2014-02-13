#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
#define getcx getchar_unlocked
int noOfNodes,noOfEdges;
inline void inp( int &n );//fast input function
inline int getInt(char **str);
inline void inpLine(char* str);
class node;
class heapMin;
class edge;
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
	void freeHeap();
	void clearHeap();
	bool check(node*);
};
class node {

public:
	unsigned int data;
	unsigned int Id;
	int indexInHeap;
	bool explored;
	vector<edge*> edges;
	edge* visitedBy;
	bool taken;
	node(int data,int Id)
	{
		this->data = data;
		this->Id = Id;
		indexInHeap = -1;
		explored = false;
		visitedBy = NULL;
		taken = false;
	}
	node();
};
class edge
{
public:
	node* first;
	node* second;
	unsigned int   weight;
	bool taken;
	edge();
	edge(node* first,node* second, unsigned int weight)
	{
		taken = false;
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
	int tempNodeStartVal,tempNodeEndVal,weight;
	char line[1000],*temp;
	while(1)
	{
		temp = line;
		inpLine(temp);
		noOfNodes = getInt(&temp);
		noOfEdges = getInt(&temp);
		if(noOfNodes == 0 && noOfEdges == 0)
			break;
		Graph = new vector<node*>(noOfNodes);
		for(int i=0;i<noOfEdges;i++)
		{
			temp = line;
			inpLine(temp);
			tempNodeStartVal = getInt(&temp);
			tempNodeEndVal =getInt(&temp);
			weight = getInt(&temp);
			tempNodeStart = (NULL == (*Graph)[tempNodeStartVal]) ? new node(10000000,tempNodeStartVal) : (*Graph)[tempNodeStartVal];
			tempNodeEnd = (NULL == (*Graph)[tempNodeEndVal]) ? new node(10000000,tempNodeEndVal) : (*Graph)[tempNodeEndVal];
			tempEdge = new edge(tempNodeStart,tempNodeEnd,weight);
			tempNodeStart->edges.push_back(tempEdge);
			(*Graph)[tempNodeEndVal] = tempNodeEnd;
			(*Graph)[tempNodeStartVal] = tempNodeStart;
		}
		int Loop[2] = {},isValid=false;
		for(int t = 0;t < 2 ;t++)
		{
			heapMin heap;
			node * Source = NULL;
			(*Graph)[0]->data = 0;
			heap.insert((*Graph)[0]);
			vector<edge*>::iterator iter;
			for(int i=0;i<noOfNodes;i++)
			{
				if(heap.getSize() > 0)
				{
					Source = heap.extractMin();
					heap.deleteNode(Source);
				}
				if(NULL != Source)
				{
					Source->explored = true;
					iter = Source->edges.begin();
					for(;iter!=Source->edges.end();++iter)
					{
						tempEdge = (*iter);
						if(true == tempEdge->taken)
							continue;
						tempNodeEnd = tempEdge->second;
						if((tempNodeEnd->explored == false))
						{
							if((Source->data + tempEdge->weight < tempNodeEnd->data))
							{
								if(tempNodeEnd -> indexInHeap >= 0)
									heap.deleteNode(tempNodeEnd);
								tempNodeEnd->data = Source->data + tempEdge->weight;
								tempNodeEnd->visitedBy = tempEdge;
								heap.insert(tempNodeEnd);
							}
						}
					}
					Source = NULL;
				}
				else
				{
					//cout<<"Graph Not Connected"<<endl;
					break;
				}
			}
			vector<edge*> path;
			if((*Graph)[noOfNodes-1]->explored == true)
			{
				isValid = true;
				Loop[t] = (*Graph)[noOfNodes-1]->data;
			}
			if(t == 0)
				isValid = false;
			tempEdge = (*Graph)[noOfNodes - 1]->visitedBy;
			tempEdge->taken=true;
			while(tempEdge)
			{
				path.push_back(tempEdge);
				tempEdge = tempEdge->first->visitedBy;
				if(tempEdge)
				{
					tempEdge->second->taken = true;
					tempEdge->taken=true;
				}
			}
/*			for(int k=path.size();k > 0;k--)
			{
				cout<<path[k-1]->first->Id<<"-( "<<path[k-1]->weight<<" )->"<<path[k-1]->second->Id<<" ; ";
				path.pop_back();
			}
			cout<<endl;*/

			int NoOfNodes = (*Graph).size();
			for(int i =0;i<NoOfNodes;i++)
			{
				if((*Graph)[i]->taken == false)
				{
					((*Graph)[i])->explored = false;
				}
					((*Graph)[i])->data = 10000000;
			}
			heap.clearHeap();
		}
		if(isValid==true)
			cout<<Loop[0]+Loop[1]<<endl;
		else
			cout<<"Not Possible"<<endl;
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
	while (c != '\n') {
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
bool heapMin::check(node* checkNode)
{
	bool leftTree = false,rightTree = false;
	int Id = checkNode->indexInHeap+1;
	unsigned int childLeft = Id*2;
	unsigned int childRight = Id*2 + 1;
	if(childLeft - 1 < heap.size())
		leftTree = check(heap[childLeft - 1]);
	else
	{
		if(heap[checkNode->indexInHeap]->data >= heap[(checkNode->indexInHeap-1)/2]->data)
			return true;
		else
			return false;
	}
	if(childRight - 1 < heap.size())
		rightTree = check(heap[childRight -1]);
	else
	{
		if(heap[checkNode->indexInHeap]->data >= heap[(checkNode->indexInHeap-1)/2]->data)
			return true;
		else
			return false;
	}
	if(leftTree == true && rightTree == true)
		return true;
	else
	{
		//cout<<"HEAP BREAKDOWN"<<endl;
		return false;
	}
}
void heapMin::clearHeap()
{
	for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		(*itr)->indexInHeap = -1;
	}
	heap.clear();
}
