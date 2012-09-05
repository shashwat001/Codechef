#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <set>
 
using namespace std;
 
int i,j;
 
#define fi(x,y) for(i = (x);i < (y);i++)
#define fj(x,y) for(j = (x);j < (y);j++)
 
 
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
 
/****************************************************************************************************/

#define MOD 1000000007
#define MOD2 2000000014
 
class Matrix
{
	public:
	long long int i,ii,iii,iv;
	
	Matrix operator*(Matrix& operand)
	{
		Matrix ret;
		ret.i = (this->i * operand.i + this->ii * operand.iii)%MOD;
		ret.ii = (this->i * operand.ii + this->ii * operand.iv)%MOD;
		ret.iii = (this->iii * operand.i + this->iv * operand.iii)%MOD;
		ret.iv = (this->iii * operand.ii + this->iv * operand.iv)%MOD;
		return ret;
	}
	
	void operator=(Matrix operand)
	{
		this->i = operand.i;
		this->ii = operand.ii;
		this->iii = operand.iii;
		this->iv = operand.iv;
	}
	
	void print()
	{
		printf("\n%lld\t%lld\n%lld\t%lld\n",this->i,this->ii,this->iii,this->iv);
	}
};
 
Matrix store[6][1001];
 
void init()
{
	Matrix a,b;
	b.i = 1;
	b.ii = 0;
	b.iii = 0;
	b.iv = 1;
	
	a.i = 1;
	a.ii = 1;
	a.iii = 1;
	a.iv = 0;
	store[0][0]=b;
	store[0][1]=a;
	
	fi(0,5)
	{
		fj(2,1000)
		{
			store[i][j]=store[i][j-1]*store[i][1];
		}
		store[i+1][0]=b;
		store[i+1][1]=store[i][999]*store[i][1];
	}
}

long long int getfib(long long int n)
{
	Matrix b,c;
	int r;
	b.i = 1;
	b.ii = 0;
	b.iii = 0;
	b.iv = 1;
	if(!n)
	{
		return 0;
	}

	i = 0;
	while(n>0)
	{
		r = n%1000;
		c=(b*store[i][r]);
		b=c;
		n=n/1000;
		i++;
	}
	return b.i;
}
int main()
{
	int t,r,rem,tot;
	long long int n,itn,sum;
	init();
	t = readInt();
	while(t--)
	{
		sum = 0;
		n = readInt();
		if(n == 1)
			sum = 1;
		for(itn = 1;itn < n;itn++)
		{
			sum += (getfib(itn)*getfib(n+3-itn))%MOD;
		}
		
		printf("%lld\n",sum%MOD);
	}
	return 0;
}
 
