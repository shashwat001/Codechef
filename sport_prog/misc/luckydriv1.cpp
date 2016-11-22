#include <cstring>
#include <cstdio>

#define MOD 1000000007




int main()
{
	int t,sum1,i,j,num,len,zeroc,k,flag;
	//long long int sum,sum2,sum3,b[9][4],c[9][4];
	long long int sum,sum3,sum2,d[4],b[9][4],c[9][4];
	char a[10001];
	scanf("%d",&t);
	//readint(t);
	while(t--)
	{
		scanf("%s",a);
		flag = 0;
		//readstr(a);
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
				if(flag==0)
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
					flag = 1;
				}
				else
				{
					for(j = 0;j < 9;j++)
					{
						b[j][0] = c[j][0];
					}
					for(j = 0;j < 9;j++)
					{
						for(k = 0;k < 3;k++)
						{
							b[(j+num)%9][k+1] = (c[(j+num)%9][k+1]+c[j][k])%MOD;
						}
					}

					b[num%9][0] = (b[num%9][0] + 1)%MOD;
					flag = 0;
				}
				
				//for(j = 0;j < 9;j++)
				//{
				//	for(k = 0;k < 4;k++)
				//		b[j][k] = c[j][k];
				//}
			}
			i++;
		}
		if(flag==0)
		{
			d[0] = b[0][0];
			d[1] = b[0][1];
			d[2] = b[0][2];
			d[3] = b[0][3];
		}
		else
		{
			d[0] = c[0][0];
			d[1] = c[0][1];
			d[2] = c[0][2];
			d[3] = c[0][3];
		}
		sum = (d[0]+d[1]+d[2]+d[3])%MOD;
		sum1 = zeroc;
		sum2 = (zeroc*(zeroc-1))/2;
		sum3 = (sum2*(zeroc-2))/3;
		if(zeroc == 1)
		{
			sum3 = 0;
		}
		sum+= (((sum1+sum2+sum3)%MOD)*d[0])%MOD + ((sum1+sum2)*d[1])%MOD + (sum1*d[2])%MOD;
		printf("%lld\n",sum%MOD);
	}
	return 0;
}
