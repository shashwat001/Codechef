#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MOD 1000000007

void readint(int &n)
{
	n = 0;
	int count = 1;
	char c;
	fread(&c,1,count,stdin);
	while(c!='\n' && c!=' ')
	{
		n = n*10+(c-48);
		fread(&c,1,count,stdin);
	}	
}

void readstr(char *str)
{
	int count = 1,i = 0;
	char c;
	fread(&c,1,count,stdin);
	while(c!='\n' && c!=' ')
	{
		str[i++] = c;
		fread(&c,1,count,stdin);
	}	
	str[i] = '\0';
}


int main()
{
	int t,i,j,num,len,zeroc,k,sum1;
	long long int sum,sum2,sum3,**b,**c,**temp;
	char a[100001];
	b = (long long int**)malloc(sizeof(long long int*)*9);
	c = (long long int**)malloc(sizeof(long long int*)*9);
	
	for(i = 0;i < 9;i++)
	{
		b[i] = (long long int*)malloc(sizeof(long long int)*4);
		c[i] = (long long int*)malloc(sizeof(long long int)*4);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		//readstr(a);
		for(i = 0;i < 9;i++)
		{
			for(j = 0;j < 4;j++)
			{
				b[i][j] = c[i][j] = 0;
			}
		}
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
					c[j][0] = b[j][0];
				}
				for(j = 0;j < 9;j++)
				{
					for(k = 0;k < 3;k++)
					{
						c[(j+num)%9][k+1] = (b[(j+num)%9][k+1]+b[j][k])%MOD;
					}
				}
				c[num%9][0] = (c[num%9][0] + 1)%MOD;
				temp = b;
				b = c;
				c = temp;
				//for(j = 0;j < 9;j++)
				//{
				//	for(k = 0;k < 4;k++)
				//		b[j][k] = c[j][k];
				//}
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
