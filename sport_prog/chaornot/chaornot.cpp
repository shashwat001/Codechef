#include <bits/stdc++.h>

using namespace std;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF,pp;
 
int readInt() {
 
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
 

int i,m,a[100005],res[100005];

/*int increasing_diff()
{
	int b[100005] = {0};
	vector<int> c(a,a+m);
	vector<int>::iterator ub;
	int n = 0,diff;
	diff = a[1] - a[0];
	for(i = 0;i < b[a[0]] && i<2;i++)
	{
		res[n++] = a[0];
	}
	for(i = 0;i < b[a[1]] && i<2;i++)
	{
		res[n++] = a[1];
	}
	ub = c.begin();
	ub++;
	while(ub != c.end())
	{
		ub = upper_bound(c.begin(),c.end(),diff+(*ub));
		if(ub!=c.end())
		{
			diff = *ub - res[0];
			for(i = 0;i < b[*ub] && i<2;i++)
			{
				res[n++] = *ub;
			}
		}
	}
	return n;
}
*/

bool el(int n)
{
	while (n)
	{
		if ((n % 3) == 2)
			return false;
 
		n /= 3;
	}
 
	return true;
}

int brute_force()
{
	srand(time(NULL));
	int valid[100005] = {0};
	int flag,b[100005],bn = 0;
	res[0] = a[0];
	res[1] = a[1];
	int n = 2,j,k;
	for(i = 2;i < m;i++)
	{
		flag = 0;
		for(j = 0;j < n;j++)
		{
			for(k = j+1;k < n;k++)
			{
				if(a[i]-res[k] == res[k]-res[j])
				{
					flag = 1;
					break;
				}

			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag == 1)
		{
			b[bn++] = a[i];
		}
		else
		{
			res[n++] = a[i];
		}
	}
	for(i = m;i < pp;i++)
	{
		b[bn++] = a[i];
	}
	n = bn = 0;
	for(i = 0;i < pp;i++)
	{
		if(el(a[i]))
		{
			res[n++] = a[i];
		}
		else
		{
			b[bn++] = a[i];
		}
	}
	for(i = 0;i < n;i++)
	{
		
		for(j = i+1;j < n;j++)
		{
			int temp[3];
			temp[0] = 2*res[i] - res[j];
			temp[1] = 2*res[j] - res[i];
			temp[2] = (res[i]+res[j])/2;
			for(k = 0;k < 3;k++)
			{
				if(temp[k]>=0 && temp[k] <= 100000)
				{
					valid[temp[k]] = 1;
				} 
			}
		}
	}
		
	for(int t = 0;t < 2000000 && bn>0;t++)
	{
		int r = rand()%bn;
		if(valid[b[r]] == 0)
		{
			res[n++] = b[r];
			for(i = 0;i < n-1;i++)
			{
				int temp[3];
				temp[0] = 2*res[i] - b[r];
				temp[1] = 2*b[r] - res[i];
				temp[2] = (res[i]+b[r])/2;
				for(k = 0;k < 3;k++)
				{
					if(temp[k]>=0 && temp[k] <= 100000)
					{
						valid[temp[k]] = 1;
					} 
				}
			}
		}
		b[r] = b[bn-1];
		bn--;
	}
	return n;
}

int main()
{
	int n,bf_limit = 13000;
	m = readInt();
	pp = m;
	for(i = 0;i < m;i++)
	{
		n = readInt();
		a[i] = n;
	}
	if(m==1)
	{
		n = 0;
		res[n++] = a[0];
	}
	else
	{
		m = min(m,bf_limit);
		sort(a,a+m);
		n = brute_force();

	}
	printf("%d\n",n);
	for(i = 0;i < n;i++)
	{
		printf("%d ",res[i]);
	}
	return 0;
}
