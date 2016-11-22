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
	char s[2050];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int cc = 0;
		scanf("%s",s);
		int l = strlen(s);
		for(i = l-1;i >= 3;i--)
		{

				 if(s[i]=='F' && s[i-1]=='?' && s[i-2]=='?' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
				}
				else if(s[i]=='F' && s[i-1]=='E' && s[i-2]=='?' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
				}
				else if(s[i]=='F' && s[i-1]=='?' && s[i-2]=='H' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
				}
				else if(s[i]=='F' && s[i-1]=='?' && s[i-2]=='?' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
				}
				else if(s[i]=='F' && s[i-1]=='?' && s[i-2]=='H' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
				}
				else if(s[i]=='F' && s[i-1]=='E' && s[i-2]=='H' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='F' && s[i-1]=='E' && s[i-2]=='?' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='F' && s[i-1]=='?' && s[i-2]=='H' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='E' && s[i-2]=='?' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='E' && s[i-2]=='H' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='E' && s[i-2]=='?' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='E' && s[i-2]=='H' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='?' && s[i-2]=='H' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='?' && s[i-2]=='H' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='?' && s[i-2]=='?' && s[i-3]=='C')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
				else if(s[i]=='?' && s[i-1]=='?' && s[i-2]=='?' && s[i-3]=='?')
				{
					s[i-3] = 'C';
					s[i-2] = 'H';
					s[i-1] = 'E';
					s[i] = 'F';
				}
			}
			for(i = 0;i < l;i++)
			{
				if(s[i]=='?')
					s[i] = 'A';
			}
			printf("%s\n",s);
		}
	return 0;
}
