#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int t,sum1,i,j,n,len,z,k,p;
//long long int sum,sum2,sum3,b[9][4],c[9][4];
long long int sum,sum3,sum2;
char a[10001];
int** daq(int b,int e)
{
	int **c,**l,**r,mid,temp,quoi,remi,quoj,remj,quok,remk;
	c = (int**)malloc(sizeof(int)*9);
	for(i = 0;i < 9;i++)
	{
		c[i] = (int*)malloc(sizeof(int)*4);
		memset(c[i],0,4*sizeof(int));
	}
	
	if(b==e)
	{
		n = a[b]-48;
		if(n == 0)
		{
			z++;
			return c;
		}
		c[n%9][0] += 1;
		return c;
	}
	mid = (b+e)/2;
	l = daq(b,mid);
	r = daq(mid+1,e);
	for(i = 0;i <9;i++)
	{
		for(j = 0;j < 3;j++)
		{
			for(k = 0;k <9;k++)
			{
				for(p = 0;p < 3;p++)
				{
					if((j+p)>2)
						continue;
					if(l[i][j] && r[k][p])
						c[(i+k)%9][j+p+1] = (l[i][j] + r[k][p])%MOD;
				}
			}
		}
	}
	for(i = 0;i < 9;i++)
	{
		c[i][0] = l[i][0] + r[i][0];
	}
	return c;
}

int main()
{
	int **res;
	scanf("%d",&t);
	//readint(t);
	while(t--)
	{
		z = 0;
		scanf("%s",a);
		len = strlen(a);
		res = daq(0,len-1);
			sum = (res[0][0]+res[0][1]+res[0][2]+res[0][3])%MOD;
		sum1 = z;
		sum2 = (z*(z-1))/2;
		sum3 = (sum2*(z-2))/3;
		if(z == 1)
		{
			sum3 = 0;
		}
		sum+= ((sum1+sum2+sum3)*res[0][0] + (sum1+sum2)*res[0][1] + sum1*res[0][2])%MOD;
		printf("%lld\n",sum);
	}

	return 0;
}
