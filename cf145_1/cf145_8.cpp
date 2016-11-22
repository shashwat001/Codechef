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
#include <fstream>


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

int main()
{
	int n,i,m,a[100001],b[100001],c[200002],cc = 0,set = 0,d[100003],dd = 0,p;
	ofstream myfile;
  	myfile.open ("output.txt");
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i = 0;i < m;i++)
	{
		scanf("%d",&b[i]);
	}
	i= n-1;j = m-1;
	while((i >= 0) || (j >= 0))
	{
		if(a[i] == 0 && i>=0)
		{
			p = 0;
			while(a[i] == 0  && i>=0)
			{
				c[cc++] = i+1;
				i--;
				p++;
			}
			while(b[j] == 0 && j>=0)
			{
				c[cc++] = j+n+1;
				j--;
				p++;
			}
			d[dd++] = p;
			set++;
		}
		if(b[j] == 0 && j>=0)
		{
			p = 0;
			while(b[j] == 0  && j>=0)
			{
				c[cc++] = j+n+1;
				j--;
				p++;
			}
			while(a[i] == 0  && i>=0)
			{
				c[cc++] = i+1;
				i--;
				p++;
			}
			d[dd++] = p;
			set++;
		}
		if(b[j] == 1 && j>=0)
		{
			p = 0;
			while(b[j] == 1  && j>=0)
			{
				c[cc++] = j+n+1;
				j--;
				p++;
			}
			while(a[i] == 1  && i>=0)
			{
				c[cc++] = i+1;
				i--;
				p++;
			}
			d[dd++] = p;
			set++;
		}
		if(a[i] == 1 && i>=0)
		{
			p = 0;
			while(a[i] == 1  && i>=0)
			{
				c[cc++] = i+1;
				i--;
				p++;
			}
			while(b[j] == 1  && j>=0)
			{
				c[cc++] = j+n+1;
				j--;
				p++;
			}
			d[dd++] = p;
			set++;
		}
	}
	j = 0;
	if((a[n-1]==0) || (b[m-1]==0))
	{
		set--;
		j = 1;
	}
		
	for(i = cc-1;i >= 0;i--)
	{
		myfile << c[i] << " ";
	}
	myfile <<endl << set << endl;
	d[dd] = 0;
	for(i = dd-1;i >= j;i--)
	{
		d[i]+= d[i+1];
		myfile << d[i] << " ";
		
	}
	
	return 0;
}
