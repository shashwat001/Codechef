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
	int t;
	t = readInt();
	while(t--)
	{
		int s,t,d;
		s = readInt();
		t = readInt();
		d = readInt();
		
		if((s+t) <d )
		{
			printf("%d.0\n",d-s-t);
		}
		else if(s+d < t)
			printf("%d.0\n",t-s-d);
		else if(t+d < s)
			printf("%d.0\n",s-d-t);
		else
		{
			printf("0.0\n");
		}
	}
	return 0;
}
