#include <bits/stdc++.h>
using namespace std;

double findgcd(double a,double b)
{
	double r;
	int d;
	while(b>0.0000100000)
	{
		d = a/b;
		r = a-b*d;
		a = b;
		b = r;
	}
	return a;
}
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}

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

int findgcdint(int a,int b)
{
	int r;
	while(b>0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
pair<bool,int> present[100005];
int main()
{
	int i,j,a[10001],max_len,n,maxi,maxdiff,b[10001],cb,flag,store[10001],diffb[10001],t,z,cs;
	double logb[10001],gcd,difflog[10001],expgcd,loga[10001];

	bool company[10001] = {false};
	inp(t);
	while(t--)
	{	
		inp(n);
		
		memset(present,0,sizeof(present));
		
		for(i = 0;i < n;i++)
		{
			inp(a[i]);
			present[a[i]].first = true;
			present[a[i]].second = i;
			loga[i] = log(double(a[i]));
		}
		if(n==2)
		{
			printf("%d %d\n",a[0],a[1]);
			printf("%d %d\n",a[0],a[1]);
			continue;
		}
		if(n==3)
		{
			printf("%d %d\n",a[0],a[1]);
			printf("%d %d\n",a[0],a[2]);
			continue;
		}
		if(n==4)
		{
			printf("%d %d\n",a[1],a[3]);
			printf("%d %d\n",a[0],a[2]);
			continue;
		}
		for(z = 0;z < 6;z++)
		{
			if(z<3)
			{
				memset(company,false,sizeof(company));
				int k,diff;
				flag = 0;
				if(z==0)
				{
					diff = a[1]-a[0];
					company[0] = true;
					k = a[1];
				}
				else if(z==1)
				{
					diff = a[2]-a[0];
					company[0] = true;
					k = a[2];
				}
				else
				{
					diff = a[2]-a[1];
					company[1] = true;
					k = a[2];
				}
				while((k<100001)&&(present[k].first))
				{
					company[present[k].second] = true;
					k = k+diff;
				}
				/*int val = a[maxi];
				for(i = 0;i < max_len;i++)
				{
					company[present[val].second] = true;
					val-=maxdiff;
				}*/
				cb = 0;
				for(i = 0;i < n;i++)
				{
					if(!company[i])
					{
						b[cb] = a[i];
						logb[cb] = loga[i];
						cb++;
					}
				}
				if(cb<=2)
				{
					for(i = 0;i < n;i++)
					{
						if(company[i])
							printf("%d ",a[i]);
					}
					printf("\n");
					if(cb==2)
					{
						
						printf("%d %d\n",b[0],b[1]);
					}
					else if(cb==1)
					{
						if(present[b[0]].second > 0)
						{
							printf("%d %d\n",a[0],b[0]);
						}
						else
						{
							printf("%d %d\n",a[0],a[1]);
						}
					}
					else
					{
						printf("%d %d\n",a[0],a[1]);
					}
					break;
				}
				for(i = 1;i < cb;i++)
				{
					difflog[i-1] = logb[i]-logb[0];
				}
				gcd = difflog[0];
				for(i = 1;i < cb-1;i++)
				{
					gcd = findgcd(difflog[i],gcd);
				}
				k = b[0];
				cs = 0;
				expgcd = exp(gcd);
				double doubk;
				while(1)
				{
					if((k<100001)&&(!present[k].first))
					{
						flag = 1;
						break;
					}
					store[cs++] = k;
					if(k==b[cb-1])
						break;
					doubk = k*expgcd;
					k = (int)doubk;
					if((doubk - k)<0.000002)
						continue; 
					if((doubk - k)>0.999998)
						k+=1;
					else
					{
						flag = 1;
						break;
					}
					
				}
				if(flag==1)
					continue;
				else
				{
					for(i = 0;i < n;i++)
					{
						if(company[i])
							printf("%d ",a[i]);
					}
					printf("\n");
					for(i = 0;i < cs;i++)
					{
						printf("%d ",store[i]);
					}
					printf("\n");
					break;
				}
			}//if(z<3)
			
			
			
			
			
			
			else
			{
				double diff,expk;
				int k,kd;
				memset(company,false,sizeof(company));
				
				if(z==3)
				{
					//diff = loga[1]-loga[0];
					diff= (double)a[1]/(double)a[0];
					company[0] = true;
					kd = a[1];
				}
				else if(z==4)
				{
					//diff = loga[2]-loga[0];
					diff= (double)a[2]/(double)a[0];
					company[0] = true;
					kd = a[2];
				}
				else
				{
					//diff = loga[2]-loga[1];
					diff= (double)a[2]/(double)a[1];
					company[1] = true;
					kd = a[2];
				}

				while((kd<100001)&&(present[kd].first))
				{
					company[present[kd].second] = true;
					expk = kd*diff;
					kd = (int)expk;
					if((expk-kd)>0.999999999998)
						kd++;
					else if(((expk-kd)<0.999999999998)&&((expk-kd)>0.000000000002))
					{
						break;
					}
				}
				/*int val = a[maxi];
				for(i = 0;i < max_len;i++)
				{
					company[present[val].second] = true;
					val-=maxdiff;
				}*/
				cb = 0;
				for(i = 0;i < n;i++)
				{
					if(!company[i])
					{
						b[cb] = a[i];
						cb++;
					}
				}
				if(cb<=2)
				{

					if(cb==2)
					{
						
						printf("%d %d\n",b[0],b[1]);
					}
					else if(cb==1)
					{
						if(present[b[0]].second > 0)
						{
							printf("%d %d\n",a[0],b[0]);
						}
						else
						{
							printf("%d %d\n",a[0],a[1]);
						}
					}
					else
					{
						printf("%d %d\n",a[0],a[1]);
					}
					for(i = 0;i < n;i++)
					{
						if(company[i])
							printf("%d ",a[i]);
					}
					printf("\n");
					break;
				}
				for(i = 1;i < cb;i++)
				{
					diffb[i-1] = b[i]-b[0];
				}
				int gcdint = diffb[0];
				for(i = 1;i < cb-1;i++)
				{
					gcdint = findgcdint(diffb[i],gcdint);
				}
				k = b[0];
				cs = 0;
				flag = 0;
				while(1)
				{
					if((k<100001)&&(!present[k].first))
					{
						flag = 1;
						break;
					}
					store[cs++] = k;
					if(k==b[cb-1])
						break;

					k = k+gcdint;
					
				}
				if(flag==1)
					continue;
				else
				{

					for(i = 0;i < cs;i++)
					{
						printf("%d ",store[i]);
					}
					printf("\n");
					for(i = 0;i < n;i++)
					{
						if(company[i])
							printf("%d ",a[i]);
					}
					printf("\n");
					break;
				}
			}//else
		}//for(z=0-6)
	}//while(t--)
	return 0;
}






