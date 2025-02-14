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

int readInt()
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

	int n = 0;
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

lli lcm(int a,int b)
{
	int k,l,r;
	lli p;
	k = max(a,b);
	l = min(a,b);
	while(l)
	{
		r = k%l;
		k = l;
		l = r;
	}
	if(k==1)
		return -1;
	return k;
	
}


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


// Miler rabin primality test
const int maxIter = 10;
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
		long long mod = modulo( a, odd, N);
		bool passes = ( mod == 1 || mod == N -1 );
		
		for(int r = 1; r < d && !passes; r ++)
		  {
			mod = mulmod( mod, mod, N);
			passes = passes || mod == N - 1;
		  }
		
		if(!passes)
			return false;
	 }
	return true;
}
// Number theory library code ends

lli power(int a, int n, int mod)
{
lli power=a,result=1;

 while(n)
 {
  if(n&1) 
   result=(result*power)%mod;
  power=(power*power)%mod;
  n>>=1;
 }
 return result;
}

bool witness(int a, int n)
{
 int t,u,i;
 lli prev,curr;

 u=n/2;
 t=1;
 while(!(u&1))
 {
  u/=2;
  ++t;
 }

 prev=power(a,u,n);
 for(i=1;i<=t;++i)
 {
  curr=(prev*prev)%n;
  if((curr==1)&&(prev!=1)&&(prev!=n-1)) 
   return true;
  prev=curr;
 }
 if(curr!=1) 
  return true;
 return false;
}

inline bool IsPrime( int number )
{
 if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
  return (false);

 if(number<1373653)
 {
  for( int k = 1; 36*k*k-12*k < number;++k)
  if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
   return (false);

  return true;
 }

 if(number < 9080191)
 {
  if(witness(31,number)) return false;
  if(witness(73,number)) return false;
  return true;
 }


 if(witness(2,number)) return false;
 if(witness(7,number)) return false;
 if(witness(61,number)) return false;
 return true;

 /*WARNING: Algorithm deterministic only for numbers < 4,759,123,141 (unsigned int's max is 4294967296)
   if n < 1,373,653, it is enough to test a = 2 and 3.
   if n < 9,080,191, it is enough to test a = 31 and 73.
   if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.
   if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.
   if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13.
   if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.*/
}


int main()
{
	int lc;
	int d,n,t,b[100001],bc = 0;
	
	t = readInt();
	/*for(i = 20000;i < 100001;i++)
	{
		for(j = 2;j < i;j++)
		{
			if(i%j == 0)
				break;
		}
		if(j == i)
		{
			printf("%d,",i);
			bc++;
		}
		
	}
	printf("\nmmmmmm %d",bc);*/
	while(t--)
	{
		n = readInt();
		d = readInt();
		lc = d;
		for(i = 1;i < n;i++)
		{
			d = readInt();
			lc = lcm(lc,d);
			if(lc==-1)
				break;
		}
		if(lc !=-1)
		{
			for(i = 0;i < bc;i++)
			{
				if((lc%b[i])==0)
				{
					lc = b[i];
					break;
				}
			}
		}
		printf("%d\n",lc);
	}
	return 0;
}
