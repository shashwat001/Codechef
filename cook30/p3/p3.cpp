#include <bits/stdc++.h>

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
	int a[10][10] = {{8,0},{9,8,7,4,3,1},{8,2},{9,8,3},{9,8,4},{9,8,6,5},{8,6},{9,8,7,3},{8},{9,8}};
	int t;
	char s[10],m[10],o[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		scanf("%s",m);
		int ls = strlen(s);
		int lm = strlen(m);
		if(lm>ls)
		{
			int d = lm-ls;
			for(i = d-1;i >= 0;i--)
			{
				o[ls+i] = m[ls+i];
			}
			i = 1;
			while(i<=ls && s[ls-i]==m[ls-i]) 
			{
				i++;
			}
			if(i==ls+1)
			{
				o[ls] = m[ls];//
			}
			if(s[ls-i]<m[ls-1])
			{
				
			}
		}
	}
	return 0;
}
