#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <iostream>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define make_pair mp
#define push_back pb

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

#define BUF 4096
char ibuf[BUF]; 
int ipt = BUF;
 
long long int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    long long int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
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
const int maxIter = 20;


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
long long int primec[10000],pc,val[10000];

long long int gcd(long long int a,long long int b)
{
	long long int t,rem;
	if(b>a)
	{
		t = b;
		b = a;
		a = t;
	}
	while(b!=0)
	{
		rem = a%b;
		a = b;
		b = rem;
	}
	return a;
}


int main()
{
	long long int n,q,i,temp,qu,t,k,gc;
	cin>>n;
	
	qu = readInt();
	pc = 0;
	int sum,cnt,j,f=1;
	if(n%2 == 0)
	{
		primec[pc++] = 2;
		cnt = 0;
		temp = n;
		while(temp%2==0)
		{
			temp = temp/2;
			cnt++;
		}
		val[pc-1] = cnt;
		f *= (cnt+1);
	}
	for(i = 3;i*i <= n;i+=2)
	{
		if(n%i==0)
		{
			q = n/i;
			if(isPrime(i))
			{
				primec[pc++] = i;
				cnt = 0;
				temp = n;
				while(temp%i==0)
				{
					temp = temp/i;
					cnt++;
				}
				val[pc-1] = cnt;
				f *= (cnt+1);
			}
			if(q!=i)
				if(isPrime(q))
				{
					primec[pc++] = q;
					cnt = 0;
					temp = n;
					while(temp%q==0)
					{
						temp = temp/q;
						cnt++;
					}
					val[pc-1] = cnt;
					f *= (cnt+1);
				}
		}
	}
	for(i = 0;i < qu;i++)
	{
		t = readInt();
		k = readInt();
		
		if(t==1)
		{
			sum = 1;
			gc = gcd(n,k);
			for(j = 0;j < pc;j++)
			{
				cnt = 1;
				while(gc % primec[j] == 0)
				{
					cnt++;
					gc = gc/primec[j];
				}
				sum = sum*cnt;
			}
			printf("%d\n",sum);
			continue;
		}
		if(t==2)
		{
			gc = n/k;
			sum = 1;
			if(!gc || (n%k!=0))
			{
				printf("0\n");
				continue;
			}
			for(j = 0;j < pc;j++)
			{
				cnt = 1;
				while(gc % primec[j] == 0)
				{
					cnt++;
					gc = gc/primec[j];
				}
				sum = sum*cnt;
			}
			printf("%d\n",sum);
			continue;
			
		}
		if(t==3)
		{
			if(n%k!=0)
			{
				printf("%d\n",f);
				continue;
			}
			for(j = 0;j < pc;j++)
			{
				sum = 1;
				cnt = val[j]+1;
				while(k%primec[j] ==0 )
				{
					k = k/primec[j];
					cnt--;
				}
				sum = sum*cnt;
			}
			printf("%d\n",f-sum);
		}
	}
	
	return 0;
}
