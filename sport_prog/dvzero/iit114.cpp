//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
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
 

lli a;

int main ()
{
	int t;
	//scanf("%d",&t);
	t = readInt();
	while(t--)
	{
		int n,i;
		int k;
		//scanf("%d %d",&n,&k);
		n = readInt();
		k = readInt();
		int c = 0,zero = 0;
		lli max1 = -1,max2 = -1;
		for(i = 0;i < n;i++)
		{
			//scanf("%d",&a[i]);
			a = readInt();
			if(a>max2 && a<=max1)
			{
				max2 = a;
			}
			else if(a>max1)
			{
				max2 = max1;
				max1 = a;
			}
			if(a<=k)
				c++;
			if(a==0)
				zero++;
		}
		if(zero >1)
		{
			printf("-1\n");
			continue;
		}
		if(c<n)
		{
			printf("%d\n",max(0,c-1));
		}
		else
		{
			if(max1<=1 && max2<=1)
			{
				printf("-1\n");
				continue;
			}
			int op = 0;
			int lcount = 0;
			while(1)
			{
				if(lcount >=30)
				{
					lcount++;
					assert(false);
				}
				if(max1*max2 <= (lli)k)
				{
					lli temp;
					temp = max1;
					max1 = max1*max2;
					max2 = temp;
					op++;
				}
				else
				{
					op++;
					break;
				}
					
			}
			printf("%d\n",n-2+op);
			continue;
		}
		
	}
	return 0;
}
