#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

lli readInt()
{
	while (ipt < BUF && ibuf[ipt] < '0')
		ipt++;

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0')
			ipt++;
	}

	lli n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0')
		n = (n*10)+(ibuf[ipt++]-'0');

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0')
			n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}

/********************************************************************************************/

int i,j;
unsigned long long mulmod(unsigned long long a,unsigned long long b,unsigned long long c)
{
	unsigned long long sum = 0,y = a % c;
	while( b )
	 {
		if(b & 1)
		  {
			sum += y;
			if( sum >= c)
					sum -= c;
		  }
		 y+=y;
		 if(y>=c) y-=c;
		b  >>= 1;
	 }
	return sum;
}


// Calculates a^b mod P
unsigned long long modulo(unsigned long long a, unsigned  long long b, unsigned  long long P)
{
	unsigned long long ans = 1;
	while( b )
	 {
		if( b & 1 )
			ans = mulmod(ans, a, P);
		  a = mulmod(a, a, P);
		  b >>= 1;
	 }
	return ans;
}


const int maxIter = 1;
bool isPrime(unsigned long long N)
{
	if(N < 2) return false;
	if( N % 2 == 0) return N == 2;
	if( N % 3 == 0) return N == 3;
	if( N % 5 == 0) return N == 5;
	if( N % 7 == 0) return N == 7;
	int d = 0;
	long long  odd = N - 1;
	while( (odd & 1) == 0)
	 {
		d++;
		odd>>= 1;
	 }
	
	for(int i = 0; i < maxIter; i++)
	 {
		long long a = rand() % ( N - 1) + 1;		// a is random number from 1 to N -1
		long long mod = modulo( a, odd, N);          	//(a^odd)%N
		bool passes = ( mod == 1 || mod == N -1 );
		
		for(int r = 1; r < d && !passes; r ++)
		  {
			mod = mulmod( mod, mod, N);	//(a*b)%N
			passes = passes || mod == N - 1;
		  }
		
		if(!passes)
			return false;
	 }
	return true;
}

int main()
{
	lli t,n;
	//scanf("%lld",&t);
	t = readInt();
	while(t--)
	{
		//scanf("%lld",&n);
		n = readInt();
		if(isPrime(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
