#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
long long int i,j;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
inline int readInt() {
 
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

int a[1000000];

int main()
{
	//freopen("input.txt","r",stdin);
	int t;
	int w,x,y,z,m,n;
	long long int sum,minm,maxm;
	t = readInt();
	while(t--)
	{
		sum = 0;
		
		n = readInt();
		m = readInt();
		memset(a,0,sizeof(int)*n);
		for(i = 0;i < m;i++)
		{
			//scanf("%lld %lld %lld %lld",&w,&x,&y,&z);
			w = readInt();
			x = readInt();
			y = readInt();
			z = readInt();
			if(w==2)
				z = -z;
			a[x-1]+=z;
			if(y!=1000000)
				a[y] -=z;
			
		}
		maxm = minm = a[0]+1;
		for(i = 0;i < n;i++)
		{
			sum+=a[i]+1;
			maxm = max(sum,maxm);
			minm = min(sum,minm);
		}
		printf("%lld\n",maxm-minm);
	}
	return 0;
}
