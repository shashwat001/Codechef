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
	int n,i;
	char a[10000];
	ofstream myfile;
  	myfile.open ("output.txt");
	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",a);
	for(i = 0;i < n/2;i++)
	{
		if(a[i] == 'R' && a[i+n/2] == 'L')
		{
			myfile << (i+n/2+1) <<" "<< (i+1) << endl;
		}
		else
		{
			myfile << (i+1) <<" "<< (i+n/2+1) << endl;
		}
	}
	return 0;
}
