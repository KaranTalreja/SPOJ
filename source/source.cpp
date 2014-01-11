#include <iostream>
#include <math.h>
using namespace std;
int main()
{
int testCases,Input;
cin>>testCases;
for (int i;i<testCases;i++)
{
	cin>>Input;
	double temp = (log2((double)Input));
	int result = temp > (int)temp ? temp+1 : temp;
	cout<<result+1<<endl;
}
return 0;
}
