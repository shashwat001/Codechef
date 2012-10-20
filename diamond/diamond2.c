#include <stdio.h>
#include <stdlib.h>


int printd(float f)
{
	int bytes = 0,i = 0,r,val;
	char buff[20],rev[20];



	if(f==0)
	{
		buff[i++] = 48;
		buff[i++] = 46;
		buff[i++] = 48;
		bytes = 1;
	}
	else
	{
		f *= (10e6);
		val = (int)f;
		while(val>0)
		{
			r = val%10;
			val = val/10;
			rev[bytes++] = r+48;
		}
		r = bytes;
		while(bytes>0)
		{
			if(bytes == 7)
			{
				buff[i++] = 46;
				buff[i++] = rev[--bytes];
				continue;
			}
			buff[i++] = rev[--bytes];
		}
		
	}
	__asm__ __volatile__ 
	(
		"movl $4, %%eax \n\t"
		"movl $1, %%ebx \n\t"
		"int $128 \n\t"
		:
		:"c"(buff), "d"(i)
	) ;
	
	
	return i;
	
} 

#define BUF 8192
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
	int t,n;
	long long *p[2001],r,s,res;
	float last;
	for(i = 0;i < 2001;i++)
	{
		p[i] = (long long *)malloc(sizeof(long long)*1001);
	}
	p[0][1] = 0;
	p[0][0] = 0;
	for(i = 1;i <= 2000; i++)
	{
		for(j = 1;j <= (i+1)/2;j++)
		{
			if(j>i/2)
			{
				r = p[i-1][i-j];
			}
			else
				r = p[i-1][j];
			if((j-1)>i/2)
			{
				s = p[i-1][i-j+1];
			}
			else
				s = p[i-1][j-1];
			p[i][j] = 1000000000 - ((r + s)>>1);
			//p[i][i+1-j] = p[i][j];
		}
	}
	t = readInt();
	while(t--)
	{
		res = 0;
		n = readInt();
		for(i = 1;i <= (n+1)/2;i++)
		{
			j = readInt();
			//if((n&1) && (i==(n+1)/2))
				//res = 2*p[n][i]*j;
			//else
				res += p[n][i]*j;
		}
		for(i = i;i <= n;i++)
		{
			j = readInt();
			res += p[n][n+1-i]*j;
		}
		last = (float)res/1000000000.0;
		//printf("%0.3lf\n",last);
		printd(last);
		printf("\n");
	}
	
	return 0;
}
