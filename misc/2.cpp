#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int i,j,l,cs = 0,f;
long long int p,d,m,res,diff;
int a[1000],b[256] = {0},c[1000];
char s[1005];

long long int getnum(int l)
{
	long long int re = 0;
	for(i = cs-1;i>=l;i--)
	{
		re = re*10 + c[i];
	}
	for(;i>=0;i--)
	{
		re = re*10 + 9;
	}
	return re;
}
int main()
{
	int r;
	cin>>p;
	cin>>d;
	m = p;
	while(m!=0)
	{
		r = m%10;
		c[cs] = r;
		a[cs++] = r;
		m = m/10;
	}
	l = cs-1;
	diff = -1;
	while(diff > d || diff<0)
	{

			res = getnum(l);
		while(p - res < 0)
			{

					j = l;
					while(c[j]==0)
					{
						c[j]= 9;
						j++;
					}
					c[j]--;
				res = getnum(l);
			}
			for(i = 0;i < cs;i++)
				c[i] = a[i];
			l--;
			diff = p-res;
	}
	cout<<p-diff;
	
	
	
	return 0;
}
