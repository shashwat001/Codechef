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

int main()
{
	char a[1000006];
	char s[1000006];
	scanf("%s",a);
	int l = strlen(a),top = 0;
	for(i = 0;i < l;i++)
	{
		if(top==0)
		{
			s[top++] = a[i];
			continue;
		}
		if(a[i] == 'x')
		{
			if(s[top-1] == 'y')
				top--;
			else
				s[top++] = 'x';
		}
		else
		{
			if(s[top-1] == 'x')
				top--;
			else
				s[top++] = 'y';
		}
		
	}
	for(i = 0;i <top;i++)
	{
		printf("%c",s[i]);
	}
	
	return 0;
}
