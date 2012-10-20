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
	int t,len,a0,a4,a7,k,a[5],b[5],*p,*q;
	char sa[20001],sb[20001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",sa);
		scanf("%s",sb);
		len = strlen(sa);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i = 0;i < len;i++)
		{
			if(sb[i] == '4') b[1]++;
			else if(sb[i] == '7') b[0]++;
			else if(sb[i] == '5' || sb[i] == '6') b[3]++;
			else if(sb[i] == '8' || sb[i] == '9') b[4]++;
			else b[2]++;
			
			if(sa[i] == '4') a[1]++;
			else if(sa[i] == '7') a[0]++;
			else if(sa[i] == '5' || sa[i] == '6') a[3]++;
			else if(sa[i] == '8' || sa[i] == '9') a[4]++;
			else a[2]++;
		} 
		k = len;
		if(a[4] >= b[4])
		{
			p = a;
			q = b;
		}
		else
		{
			p = b;
			q = a;
		}
		k = p[4];
		j = 4;
		while(k >= q[j])
		{
			k = k-q[j];
			q[j] = 0;
			j--;
		}
		q[j] -= k;
		p[4] = 0;
		
		k = a[0];
		j = 4;
		while(k >= b[j])
		{
			k = k-b[j];
			b[j] = 0;
			j--;
		}
		b[j] -= k;
		l7 = a[0];
		a[0] = 0;
		
		k = b[0];
		j = 4;
		while(k >= a[j])
		{
			k = k-a[j];
			a[j] = 0;
			j--;
		}
		a[j] -= k;
		l7 += b[0];
		b[0] = 0;
		
		
		
		if(a[3] >= b[3])
		{
			p = a;
			q = b;
		}
		else
		{
			p = b;
			q = a;
		}
		
		k = p[3];
		j = 3;
		while(k >= q[j])
		{
			k = k-q[j];
			q[j] = 0;
			j--;
		}
		q[j] -= k;
		p[3] = 0;
		
		
		k = a[1];
		j = 4;
		while(k >= b[j])
		{
			k = k-b[j];
			b[j] = 0;
			j--;
		}
		b[j] -= k;
		l4 = a[1];
		a[1] = 0;
		
		k = b[1];
		j = 4;
		while(k >= a[j])
		{
			k = k-a[j];
			a[j] = 0;
			j--;
		}
		a[j] -= k;
		l4 += b[1];
		b[1] = 0;
		/*for(i = 0;i < 5;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		for(i = 0;i < 5;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
		printf("%d %d",l4,l7);
		
		printf("\n\n");*/
		for(i = 0;i < l7;i++)
		printf("7");
		for(i = 0;i < l4;i++)
		printf("4");
		printf("\n");
		
	}
	return 0;
}
