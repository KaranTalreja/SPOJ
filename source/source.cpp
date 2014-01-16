#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
#include <vector>
using namespace std;
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

	int count =0;
	hash_first_itr = hash_first.begin();
	for(;hash_first_itr != hash_first.end();++hash_first_itr)
	{
		int node,size = hash_first_itr->second->size(),min = 1000000;
		for(int i=0;i<size;i++)
		{
			node = (*(hash_first_itr->second))[i];
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
			count++;
		}
	}


	printf("%d\n",count);
	return 0;
}
