#include <iostream>
#include <stdio.h>
#include <math.h>
class moduloArith
{
	long long P;
	public:
	moduloArith(long long prime)
	{
		P = prime;
	}
	moduloArith();
	long long add(long long A, long long B)
	{
		return ( (A % P + B % P) % P);

	}
	long long subtract(long long A, long long B)
	{
		return (((A % P - B % P) + P) % P);
	}
	long long multiply(long long A, long long B)
	{
		return ((A % P * B % P) % P);
	}
	long long divide(long long A,long long B)
	{
		return (((A % P) * (pow(B,P-2) % P )) % P);
	}
	long long exp(long long A, long long pow)
	{
		if(A == 1)
			return 1;
		long long retVal = 1;
		for(long long i=0;i<pow;i++)
		{
			retVal = multiply(retVal,A);
		}
		return retVal;
	}
	/* This function calculates (a^b)%MOD */
	long long pow(long long A, long long B)
	{
	long long x = 1, y = A;
	    while(B > 0) {
	        if(B%2 == 1) {
	            x=(x*y);
	            if(x>P) x%=P;
	        }
	        y = (y*y);
	        if(y>P) y%=P;
	        B /= 2;
	    }
	    return x;
	}
};
int main()
{	
	int N=1,L=1;
	moduloArith modulo(1000000007);
	long long retVal=0;
	int count=0;
	int j;
	while(1)
	{
		scanf("%d %d",&N,&L);
		if(N == 0 && L == 0 )
			break;
		retVal = modulo.exp(N,L+1);
		retVal = modulo.subtract(retVal,N);
		retVal = modulo.divide(retVal,N-1);
		printf("%llu\n",retVal);
	}

	return 0;
}
