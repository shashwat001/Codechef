#include <bits/stdc++.h>

using namespace std;





#define BUF 65000
char ibuf[BUF]; 
int ipt = BUF;
 
int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
}
 


char a[10000000] = {0};
int b[10000000] = {0};
int bc = 0;

int pip(int n , int p)
{
    long long temp=0;
    long long mult = (long long)p;
    while(1)
    {
        if(n<mult) break;
        temp += (long long)n/mult;
        mult = mult*p ;
    }
    return temp;
}


long long apown(long long int x,int y,int z)
{
	long long res = 1;
	while(y>0)
	{
		if(y&1)
		{
			res = (res*x)%z;
			y = y>>1;
			x = (x*x)%z;
		}
	}
	return res;
}

int main()
{
	int i = 2,n,m,d,k,j,pn,pd,diff,dd;
	long long rem;
	while(i <= 10000000)
	{
		if(a[i] == 0)
		{
			b[bc++] = i;
			j = i+i;
			while(j <= 10000000)
			{
				a[j] = 1;
				j+=i;
			}
		}
		i++;
	}
	b[0] = 2;
	int t,flag;
	t = readInt();
	while(t--)
	{
		flag = 0;
		//scanf("%d %d %d",&n,&d,&m);
		n = readInt();
		d = readInt();
		m = readInt();
		for(k = 0;b[k] <= max(n,d);k++)
		{
			pn = pip(n,b[k]);
			dd = d;
			pd = 0;
			while(dd%b[k]==0)
			{
				pd++;
				dd = dd/b[k];
			}
			if(pd > pn)
			{
				printf("-1\n");
				flag = 1;
				break;
			}
			
		}
		if(flag == 1)
			continue;
		rem = 1;
		for(k = 0;b[k] <= n;k++)
		{
			pn = pip(n,b[k]);
			dd = d;
			pd = 0;
			while(dd%b[k]==0)
			{
				pd++;
				dd = dd/b[k];
			}
			diff = pn-pd;
			rem = (rem *apown(b[k],diff,m))%m;
		
		}
		printf("%lld\n",rem);
	}
	return 0;
}
