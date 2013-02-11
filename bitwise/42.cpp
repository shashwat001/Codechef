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
 
long long readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    long long n = 0;
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
#define MOD2 1000000007
#define BASE 1000
 
class Matrix
{
	public:
	long long int a[4][4];
	
	Matrix operator*(Matrix& operand)
	{
		Matrix ret;
		/*ret.i = (this->i * operand.i + this->ii * operand.iii)%MOD2;
		ret.ii = (this->i * operand.ii + this->ii * operand.iv)%MOD2;
		ret.iii = (this->iii * operand.i + this->iv * operand.iii)%MOD2;
		ret.iv = (this->iii * operand.ii + this->iv * operand.iv)%MOD2;*/
		int ii,kk,jj;
		for(ii = 0;ii < 4;ii++)
		{
			for(jj = 0;jj < 4;jj++)
			{
				ret.a[ii][jj] = 0;
				for(kk = 0;kk < 4;kk++)
				{
					ret.a[ii][jj] += (this->a[ii][kk] * operand.a[kk][jj])%MOD2;
					ret.a[ii][jj] = ret.a[ii][jj]%MOD2;
				}
			}
		}
		return ret;
	}
	
	void operator=(Matrix operand)
	{
		int ii,jj;
		for(ii = 0;ii < 4;ii++)
		{
			for(jj = 0;jj < 4;jj++)
			{
				this->a[ii][jj] = operand.a[ii][jj];
			}
		}
	}
	
	/*void print()
	{
		printf("\n%lld\t%lld\n%lld\t%lld\n",this->i,this->ii,this->iii,this->iv);
	}*/
};
 
Matrix store[7][BASE];
 
void init()
{
	Matrix a,b;
	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 4;j++)
		{
			b.a[i][j] = (i==j);
		}
	}
	
	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 4;j++)
		{
			a.a[i][j] = 0;
		}
	}
	
	a.a[0][0] = 1;
	a.a[0][1] = 2;
	a.a[0][2] = 3;
	a.a[0][3] = 1;
	a.a[1][0] = 1;
	a.a[2][1] = 1;
	a.a[3][2] = 1;
	store[0][0]=b;
	store[0][1]=a;
	
	for(i = 0;i < 6;i++)
	{
		for(j = 2;j < BASE;j++)
		{
			store[i][j]=store[i][j-1]*store[i][1];
		}
		store[i+1][0]=b;
		store[i+1][1]=store[i][BASE-1]*store[i][1];
	}
}
int main()
{
	long long t,r;
	long long n;
	Matrix b,c;
	init();
	t = readInt();
	while(t--)
	{
		for(i = 0;i < 4;i++)
		{
			for(j = 0;j < 4;j++)
			{
				b.a[i][j] = (i==j);
			}
		}
		n = readInt();
		if(!n)
		{
			printf("0\n");
			continue;
		}
		
/*		if(n==1000000000)
		{
			printf("187500002\n");
			continue;
		}*/
		
		
		if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(n==2)
        {
            printf("2\n");
            continue;
        }
         if(n==3)
        {
            printf("5\n");
            continue;
        }
         if(n==4)
        {
            printf("12\n");
            continue;
        }
		
		i = 0;
		
		n = n-4;
		while(n>0)
		{
			r = n%BASE;
			c=(b*store[i][r]);
			b=c;
			n=n/BASE;
			i++;
		}
		long long output;
		output = (12 *b.a[0][0] + 5*b.a[0][1] + 2*b.a[0][2] + b.a[0][3] ) % MOD2;
		printf("%lld\n",output);
	}
	return 0;
}
