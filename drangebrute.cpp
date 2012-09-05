#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>


using namespace std;

long long int i,j;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
int readInt() {
 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
 
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
 
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    }
    return n;
}

/**********************************************************************************************/

long long int a[1000000];

void initialize(int n)
{
	for(i = 0;i < n;i++)
	{
		a[i] = i+1;
	}
}
int main()
{
	int t;
	//freopen("input.txt","r",stdin);
	long long int w,x,y,z,m,n,maxn,minn;
	t = readInt();
	while(t--)
	{
		//scanf("%lld %lld",&n,&m);
		n = readInt();
		m = readInt();
		initialize(n);
		for(i = 0;i < m;i++)
		{
			//scanf("%lld %lld %lld %lld",&w,&x,&y,&z);
			w = readInt();
			x = readInt();
			y = readInt();
			z = readInt();
			if(w==2)
				z = -z;
			for(j = x-1;j<=y-1;j++)
			{
				a[j]+=z;
			}
		}
		maxn = minn = a[0];
		for(i = 0;i < n;i++)
		{
			maxn = max(a[i],maxn);
			minn = min(a[i],minn);
		}
		printf("%lld\n",maxn-minn);
		
	}
	return 0;
}
