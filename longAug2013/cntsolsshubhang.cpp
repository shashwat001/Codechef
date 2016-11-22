#include<stdio.h>
#define mod 1000000007
int main()
{
	long long int i,j,count,k,l,m,n,t,upper,mymod,d,N,no1,no2,times,no3,j1,k1,l1,c1,c2,c3,no11,no22,no33;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		count=0;
		scanf("%lld%lld%lld%lld",&upper,&d,&m,&N);
		if(d==0)
		{
			if(3%N==m)
			{
				count = ((((upper + 1)*(upper+1))%mod)*(upper+1))%mod;	
			}
		}
		else
		{
			for(j=0;j<N&&j<=upper;j++)
			{
				for(k=j;k<N&&k<=upper;k++)
				{
					for(l=k;l<N&&l<=upper;l++)
					{
						no11=j;
						no1=1;
						no22=k;
						no2=1;
						no33=l;
						no3=1;
						c1=upper/N;
						c2=upper/N;
						c3=upper/N;
						mymod = upper % N;
						if(j<=mymod)
							c1++;
						if(k<=mymod)
                                               		c2++;
						if(l<=mymod)
                                               		c3++;
						times=d;
						while(times!=0)
						{
							if(times&1)
							no1=(no11*no1)%N;
							times=times>>1;
							no11=(no11*no11)%N;
						}
						times=d;
                                                while(times!=0)
                                                {
                                                        if(times&1)
                                                        no2=(no22*no2)%N;
                                                        times=times>>1;
                                                        no22=(no22*no22)%N;
                                                }
						times=d;
                                                while(times!=0)
                                                {
                                                        if(times&1)
                                                        no3=(no3*no33)%N;
                                                        times=times>>1;
                                                        no33=(no33*no33)%N;
                                                }
						//for(j1=0;j1<d-1;j1++)
						//{
						//	no1=(no1*no1)%N;
						//}
						//for(k1=0;k1<d-1;k1++)
                                               	//{	
                                                //       	no2=(no2*no2)%N;
                                               	//}
						//for(l1=0;l1<d-1;l1++)
                                               	//{
                                                //       	no3=(no3*no3)%N;
                                               	//}
						//printf("j,k,l  %lld %lld %lld\n",j,k,l);
						//printf("c1,c2,c3 %lld %lld %lld\n",c1,c2,c3);
						//printf("no1,no2,no3 %lld %lld %lld\n",no1,no2,no3);
						if((no1+no2+no3)%N==m)
						{
							//printf("%lld %lld %lld\n",no1,no2,no3);
							if(j==k&&k==l)
							{
								count = (count + (((c1*c2)%mod)*c3)%mod)%mod;
							}
							else if(j==k && k!=l)
							{
								count = (count + (((((c1*c2)%mod)*c3)%mod)*3)%mod)%mod;
							}
							else if(k==l && j!=l)
                                                        {
								count = (count + (((((c1*c2)%mod)*c3)%mod)*3)%mod)%mod;
                                                        }
							else
							{
								count = (count + (((((c1*c2)%mod)*c3)%mod)*6)%mod)%mod;
							}
							//printf("c1,c2,c3 %lld %lld %lld\n",c1,c2,c3);
							//printf("count - %d\n",count);
						}
					}
				}
			}
		}
		printf("%lld\n",count);	
	}
	return 0;
}
