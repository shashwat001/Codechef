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

int temp[2][400010];
int modi[400010];
#define MOD 1000000007
 
 
 
int modmulinverse(int a,int m)
{
    int x = 0,y = 1,u = 1,v = 0; 
    int e = m,f = a;
    int c,d,q,r;
    lli z;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    } 
    u =  (u+m)%m;
    return u;
}
 
 
int main()
{
    int r,n,m,a,b,cnr = 0;
	int sum;
	lli k,l;
	for(i = 1;i <= 400000;i++)
	{
		modi[i] = modmulinverse(i,MOD);
	} 
	r = readInt();
	for(i = 0;i <r;i++)
	{
		n = readInt();
		m = readInt();
		a = readInt();
		b = readInt();
		k = 1;
		for(j = 1;j < b;j++)
		{
			l = ((lli)(n-a+j)*(lli)modi[j])%MOD;
			k = (k*l)%MOD;
			
		}
		for(;j <= m;j++)
		{
			l = ((lli)(n-a+j)*(lli)modi[j])%MOD;
			k = (k*l)%MOD;
			temp[0][m-j] = k;
		}
		k = 1;
		temp[1][0] = 1;
		sum = temp[0][0];
		for(j = 1;j <= m-b;j++)
		{
			l = ((lli)(a-1+j)*(lli)modi[j])%MOD;
			k = (k*l)%MOD;
			temp[1][j] = k;
			l = ((lli)temp[0][j]*(lli)temp[1][j]);
			l = l%MOD;
			sum=(sum+l)%MOD;
		}
		printf("%d\n",sum);
	}

	return 0;
}

