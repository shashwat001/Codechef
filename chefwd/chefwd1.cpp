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
#define BASE 1050
 
class Matrix
{
	public:
	long long int m[4][4];
	
	Matrix operator*(Matrix& operand)
	{
		Matrix ret;
		int iti,itj,itk;
		long long int val,q;
		for(iti = 0;iti < 4;iti++)
		{
			for(itj = 0;itj < 4;itj++)
			{
				ret.m[iti][itj] = 0;
				for(itk = 0;itk < 4;itk++)
				{
					val = (this->m[iti][itk]*operand.m[itk][itj])%MOD;
					if(val < 0)
						val+=MOD;
					ret.m[iti][itj] = (ret.m[iti][itj] + val)%MOD;
					if(ret.m[iti][itj] < 0)
						ret.m[iti][itj]+=MOD;
				}
			}
		}
		return ret;
	}
	
	void operator=(Matrix operand)
	{
		int iti,itj;
		for(iti = 0;iti < 4;iti++)
		{
			for(itj = 0;itj < 4;itj++)
			{
				this->m[iti][itj] = operand.m[iti][itj];
			}
		}
	}
	

};
 
Matrix store[6][BASE+1];
char s[180001],temps[18];
int cs = 0,ctemps;
 
void init()
{
	Matrix a,b;
	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 4;j++)
		{
			if(i==j) b.m[i][j] = 1;
			else b.m[i][j] = 0;
		}
	}
	
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 4;j++)
		{
			if(i==j)
				a.m[i+1][j] = 1;
			else
				a.m[i+1][j] = 0;
		}
	}
	a.m[0][0] = 2; a.m[0][1] = 1; a.m[0][2] = -2; a.m[0][3] = -1;
	store[0][0]=b;
	store[0][1]=a;
	
	fi(0,5)
	{
		fj(2,BASE)
		{
			store[i][j]=store[i][j-1]*store[i][1];
		}
		store[i+1][0]=b;
		store[i+1][1]=store[i][BASE-1]*store[i][1];
	}
}

int getfib()
{
	Matrix b,c;
	int r;
	long long int temp,q;

	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 4;j++)
		{
			if(i==j) b.m[i][j] = 1;
			else b.m[i][j] = 0;
		}
	}


	i = 0;
	ctemps = 0;
	while(s[cs]!='\n')
	{
		temps[ctemps++] = s[cs++];
	}
	cs++;
	int n = ctemps-1;
	if(ctemps==1)
	{
		switch(temps[0])
		{
			case '0': return 0;break;
			case '1': return 0; break;
			case '2': return 5; break;
			case '3': return 18; break;
			case '4': return 44;break;
			case '5': return 96; break;
		}
	}
	while(n>=0)
	{
		r = 0;
		j = 0;
		int k = 1;
		while(j<3 && n >= 0)
		{
			r += (temps[n] - '0')*k;
			k = k*10;
			j++;
			n--;
		}
		c=(b*store[i][r]);
		b=c;
		i++;
	}

	temp = (b.m[0][0]*96+b.m[0][1]*44+b.m[0][2]*18+b.m[0][3]*5)%MOD;
	if(temp < 0)
		temp+=MOD;
	return (int)temp;
}
int main()
{
	int t=0,r,rem,tot;
	long long int n,itn;
	int sum;
	init();
	fread(s,180000,1,stdin);
	ctemps = 0;
	while(s[cs]!='\n')
	{
		t = t*10 + s[cs++] - '0';
	}
	cs++;

	//t = readInt();
	while(t--)
	{
		sum = 0;
		//n = readInt();
		sum = getfib();
		
		printf("%d\n",sum);
	}
	return 0;
}
 
