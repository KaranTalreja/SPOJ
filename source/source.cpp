#include <stdio.h>
#include <iostream>
#include <tr1/unordered_map>
using namespace std;
int main()
{	
	int N,M,P,first,second;
	tr1::unordered_map<int,int> hash;
	tr1::unordered_map<int,int> hash_second;
	tr1::unordered_map<int,int> hash_left;
	tr1::unordered_map<int,int> hash_left_second;
	scanf("%d %d %d",&N,&M,&P);
	for(int i=0;i<P;i++)
	{
		scanf("%d %d",&first,&second);
		hash.insert(tr1::unordered_map<int,int>::value_type(first,second));
		hash_left.insert(tr1::unordered_map<int,int>::value_type(second,first));
	}
	tr1::unordered_map<int,int>::iterator itr = hash.begin();
	for(;itr!=hash.end();++itr)
		hash_second.insert(tr1::unordered_map<int,int>::value_type(itr->second,itr->first));
	tr1::unordered_map<int,int>::iterator itr2 = hash_left.begin();
	for(;itr2!=hash_left.end();++itr2)
		hash_left_second.insert(tr1::unordered_map<int,int>::value_type(itr2->second,itr2->first));
	printf("%d\n",(hash_second.size() > hash_left_second.size()) ? (int)hash_second.size() : (int)hash_left_second.size());
	return 0;
}
