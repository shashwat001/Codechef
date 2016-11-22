#include <string.h>
#include <stdio.h>

#define MOD 1000000007



int main()
{
	int t,i,j,num,len,zeroc,k,sum1;
	long long int sum,sum2,sum3,b[9][4],c[9][4];
	char a[10001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		len = strlen(a);
		i = 0;
		zeroc = 0;
		sum = 0;
		while(i<len)
		{
			num = a[i]-48;
			if(num == 0)
				zeroc++;
			else
			{
				for(j = 0;j < 9;j++)
				{
					for(k = 0;k < 3;k++)
					{
						c[(j+num)%9][k+1] = (b[(j+num)%9][k+1]+b[j][k])%MOD;
					}
				}
				c[num%9][0] = (c[num%9][0] + 1)%MOD;
				for(j = 0;j < 9;j++)
				{
					for(k = 0;k < 4;k++)
						b[j][k] = c[j][k];
				}
			}
			i++;
		}
		sum = b[0][0]+b[0][1]+b[0][2]+b[0][3];
		sum1 = zeroc;
		sum2 = (zeroc*(zeroc-1))/2;
		sum3 = (sum2*(zeroc-2))/3;
		if(zeroc == 1)
		{
			sum3 = 0;
		}
		sum+= (((sum1+sum2+sum3)%MOD)*b[0][0])%MOD + ((sum1+sum2)*b[0][1])%MOD + (sum1*b[0][2])%MOD;
		printf("%lld\n",sum%MOD);
	}
	return 0;
}
