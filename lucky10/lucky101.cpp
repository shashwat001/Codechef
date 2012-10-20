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

int i,j,l4,l7;

void print()
{
	while(l7--)
		printf("%d",7);
	while(l4--)
		printf("%d",4);
	printf("\n");
}


int main()
{
	int t,len,a0,a4,a7,k,a56,a89,b0,dif,b4,b7,b56,b89;
	char a[20001],b[20001];

		scanf("%s",a);
		scanf("%s",b);
		len = strlen(a);
		a0 = b0 = a4 = b4 = a56 = b56 = a7 = b7 = a89 = b89 = 0;
		for(i = 0;i < len;i++)
		{
			if(b[i] == '4') b4++;
			else if(b[i] == '7') b7++;
			else if(b[i] == '5' || b[i] == '6') b56++;
			else if(b[i] == '8' || b[i] == '9') b89++;
			else b0++;
			
			if(a[i] == '4') a4++;
			else if(a[i] == '7') a7++;
			else if(a[i] == '5' || a[i] == '6') a56++;
			else if(a[i] == '8' || a[i] == '9') a89++;
			else a0++;
		} 
		k = len;
		l7 = l4 = 0;
		if(a89 >= b89)
		{
			dif = a89 - b89;
			if(dif >= b56)
			{
				dif = dif - b56;
				b56 = 0;
			}
			else
			{
				dif = 0;
				b56 = b56-dif;
			}
			if(dif >= b0)
			{
				dif = dif - b0;
				b0 = 0;
			}
			else
			{
				dif = 0;
				b0 = b0-dif;
			}
			if(dif >= b4)
			{
				dif = dif - b4;
				b4 = 0;
			}
			else
			{
				dif = 0;
				b4 = b4-dif;
			}
		}
		printf("%d %d %d %d %d\n",b0,b4,b56,b7,b89);
	return 0;
}
