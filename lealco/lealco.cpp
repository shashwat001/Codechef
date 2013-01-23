#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

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

/********************************************************************************************/

int i,j;
int t,n,k,m,r[18],maxm,maxcnt;

int recurse(int i,int arr[]);
int main()
{
	int inp1[18];
	t = readInt();
	while(t--)
	{
		n = readInt();
		k = readInt();
		m = readInt();
		for(i =0 ;i < n;i++)
		{
			r[i] = readInt();
			inp1[i] = r[i];
		}
		if(m == 1)
		{
			printf("-1\n");
			continue;
		}
		int res = recurse(0,inp1);
		if(res!=999)
			printf("%d\n",res);
		else
			printf("-1\n");
	}
	return 0;
}

int recurse(int i,int arr[])
{
	if(i<n)
	{
            int a[18];
            for(int j=0;j<n;j++)
            {
          		a[j]=arr[j];
        	}    // without increment case
            int aa=recurse(i+1,a);
            a[i]++; // with incremented case
            int bb=recurse(i+1,a);
            int c=min(aa,bb);  // choosing minimum value
            return c;
    }
    else
    {
        //for(int y=0;y<n;++y)
			//printf("%d",r[y]);
        //printf("\n");
            
        int maxm=0;
        
        int maxf=0;
        bool good=true;
        for(int x=0;x<=n-k;x++)
        {
            maxm=0;maxf=0;
            for(int y=x;y<k+x;y++)
            {
               maxm=max(maxm,arr[y]); 
            }
            for(int y=x;y<k+x;y++)
            {
               if(arr[y]==maxm) maxf++; 
            }
            if(maxf>=m) 
            	good=false;

        }
        int change=0;
        for(int x=0;x<n;x++)
        {
            if(arr[x]!=r[x]) 
            	change++;
        }
        if(good==true)
        	return change;
        else 
        	return 999;
    }
}
