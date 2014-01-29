#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <vector>
using namespace std;
class node;
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
};
class node {

public:
	int data;
	vector<int> *edge;
	int edges;
	node(int data,vector<int> *edge)
	{
		this->data = data;
		this->edge = edge;
		edges = edge->size();
	}
	node();

};
int main()
{	
	int N,M,P,first,second;
	tr1::unordered_map<int,vector<int>* > hash_first;
	tr1::unordered_map<int,vector<int>* > hash_second;
	tr1::unordered_map<int,vector<int>* >::iterator hash_first_itr;
	tr1::unordered_map<int,vector<int>* >::iterator hash_second_itr;
	tr1::unordered_map<int,vector<int>* >::iterator temp_itr;
	tr1::unordered_map<int,vector<int>* >::iterator temp_itr_bk;
	vector<int> *temp ;
	scanf("%d %d %d",&N,&M,&P);
	for(int i=0;i<P;i++)
	{
		scanf("%d %d",&first,&second);
 		hash_first_itr = hash_first.find(first);
 		if(hash_first_itr == hash_first.end())
 		{
 			temp = new vector<int>;
 			temp->push_back(second);
 			hash_first.insert(tr1::unordered_map<int,vector<int>* >::value_type(first,temp));
 		}
 		else
 			hash_first_itr->second->push_back(second);
 		hash_second_itr = hash_second.find(second);
 		if(hash_second_itr == hash_second.end())
 		{
 			temp = new vector<int>;
 			temp->push_back(first);
 			hash_second.insert(tr1::unordered_map<int,vector<int>* >::value_type(second,temp));
 		}
 		else
 			hash_second_itr->second->push_back(first);
	}

	heapMin heap;
	int count =0;
	hash_first_itr = hash_first.begin();
	for(;hash_first_itr != hash_first.end();++hash_first_itr)
	{
		heap.insert(new node(hash_first_itr->first,hash_first_itr->second));
	}
	int Size = heap.getSize();
	for(int i=0;i<Size;i++)
	{
		node* minNode = heap.extractMin();
		int node,size = minNode->edge->size(),min = 1000000;
        for(int i=0;i<size;i++)
        {
            node = (*(minNode->edge))[i];
            temp_itr = hash_second.find(node);
            if(temp_itr != hash_second.end())
            {
                if(temp_itr->second->size() < min)
                {
                    temp_itr_bk = temp_itr;
                    min = temp_itr->second->size();
                }
            }
        }
        if(min < 1000000)
        {
            hash_second.erase(temp_itr_bk);
            hash_first_itr = hash_first.find(minNode->data);
            hash_first.erase(hash_first_itr);
            count++;
        }
	}

	//heap.decompile();
	printf("%d\n",count);
	return 0;
}
void heapMin::insert(node* Edge)
{
	int parent,child;
	node* tempEdge;
	heap.push_back(Edge);
	size++;
	child = size;
	parent = (child)/2;
	while((parent >=1) && (heap[parent-1]->edges > heap[child-1]->edges))
	{
		tempEdge = heap[child-1];
		heap[child-1] = heap[parent-1];
		heap[parent-1] = tempEdge;
		child = parent;
		parent = parent/2;
	}

}

node* heapMin::extractMin(void)
{
	node* retVal = heap[0],*tempEdge;
	tempEdge = heap[0];
	heap[0] = heap[size-1];
	heap[size-1] = tempEdge;
	vector<node*> :: iterator itr = heap.begin();
	itr = itr + size -1;
	heap.erase(itr);
	size--;
	int parent = 1;
	int child = parent;
	while(2*parent <= size)
	{
		if(2*parent != size)
		{
		child = (heap[(2*parent)-1]->edges <= heap[(2*parent)]->edges) ? 2*parent : 2*parent + 1;
		if(heap[child-1]->edges < heap[parent-1]->edges)
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
			if(heap[child-1]->edges < heap[parent-1]->edges)
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
//void heapMax::deleteNode(node* del)
//{
//	node* tempEdge;
//	int parent = del->indexInHeap + 1;
//	tempEdge = heap[del->indexInHeap];
//	heap[del->indexInHeap] = heap[size-1];
//	heap[del->indexInHeap]->indexInHeap = del->indexInHeap;
//	heap[size-1] = tempEdge;
//	vector<node*> :: iterator itr = heap.begin();
//	itr = itr + size -1;
//	size--;
//
//	int child = parent;
//	while(2*parent <= size)
//	{
//		if(2*parent != size)
//		{
//		child = (heap[(2*parent)-1]->data >= heap[(2*parent)]->data) ? 2*parent : 2*parent + 1;
//		if(heap[child-1]->data > heap[parent-1]->data)
//		{
//			tempEdge = heap[child -1];
//			heap[child - 1] = heap[parent - 1];
//			heap[child-1]->indexInHeap = child-1;
//			heap[parent - 1] = tempEdge;
//			heap[parent-1]->indexInHeap = parent-1;
//			parent = child;
//		}
//		else
//			break;
//		}
//		else
//		{
//			child = 2*parent;
//			if(heap[child-1]->data > heap[parent-1]->data)
//			{
//				tempEdge = heap[child -1];
//				heap[child - 1] = heap[parent - 1];
//				heap[child-1]->indexInHeap = child-1;
//				heap[parent - 1] = tempEdge;
//				heap[parent-1]->indexInHeap = parent-1;
//				parent = child;
//			}
//			else
//				break;
//		}
//	}
//	(*itr)->indexInHeap = 0;
//	heap.erase(itr);
//}
void heapMin::decompile()
{
	for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		cout<<(*itr)->data<<" ";
	}
	cout<<endl;
		for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
		{
			cout<<(*itr)->edges<<" ";
		}
		cout<<endl;

}
