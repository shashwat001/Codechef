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
#include <cassert>

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

lli readInt()
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

	lli n = 0;
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

#define fmod 999
int a[34][34];
int i,j;
lli temp[50000],tempval,rem;

struct _allnum
{
	lli d;
	int idx;
} num[fmod][10000];

lli makenum(int n,int m)
{
	int bit = 0;
	lli pow2 = 1;
	lli sum = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
		{
			if(a[i][j] == 1)
			{
				sum += pow2;
			}
			pow2 = 2*pow2;
		}
	}
	return sum;
}



int main()
{
	int n,m,p,q,x,y,k,c,p1[6],p2[6],b[34][34],z,ctemp,rot = -1,cnt,l,mod,ans;
	lli val,ressum,sumdiff,rat,count1[50000];
	//for(n = 1;n <= 34;n++){
	//for(m = 1;m <= 34/n;m++){
	n = readInt();
	m = readInt();
	q = readInt();
	//for(x = 1;x <= n;x++){
	//for(y = 1;y <= m;y++){
	x = readInt();
	y = readInt();
	memset(num,0,sizeof(num));
	for(i = 0;i < 6;i++)
	{
		p1[i] = readInt();
		//p1[i] = 1;
		//p2[i] = 1;
		p2[i] = readInt();
	}
	memset(a,0,sizeof(a));
	a[x-1][y-1] = 1;
	//temp[0][x-1][y-1] = 1;
	temp[0] = makenum(n,m);
	//rem = temp[0]%fmod;
	//num[rem][0].d++;
	//num[rem][num[rem][0].d].d = temp[0];
	//num[rem][num[rem][0].d].idx = 0;
	ctemp = 1;
	memset(count1,0,sizeof(count1));
	count1[0] = 1;
	/*for(j = 0;j < n;j++)
	{
		for(k = 0;k < m;k++)
		{
			//printf("%d\t",a[j][k]);
		}
		//printf("\n");
	}
	//printf("\n\n\n");*/
	cnt = 1;
	while(rot == -1)
	{
		memset(b,0,sizeof(b));
		for(j = 0;j <n;j++)
		{
			for(k = 0;k < m;k++)
			{
				if(a[j][k] == 1)
				{
					c = 0;
					for(p = 0;p < m;p++)
					{
						if(a[j][p] == 1)
							c++;
					}
					for(p = 0;p < n;p++)
					{
						if(a[p][k] == 1)
							c++;
					}
					c--;
					c = c%6;
					switch(c)
					{
						case 0:
							b[j][k]++;
							i = j;
							i = i-p1[c];
							while(i>=0 && i<n)
							{
								b[i][k]++;
								i = i-p1[c];
							}
							i = j;
							i = i+p2[c];
							while(i>=0 && i<n)
							{
								b[i][k]++;
								i = i+p2[c];
							}
							break;
						case 1:
							b[j][k]++;
							i = k;
							i = i-p1[c];
							while(i>=0 && i<m)
							{
								b[j][i]++;
								i = i-p1[c];
							}
							i = k;
							i = i+p2[c];
							while(i>=0 && i<m)
							{
								b[j][i]++;
								i = i+p2[c];
							}
							break;
						case 2:
							b[j][k]++;
							i = j;
							i = i-p1[c];
							while(i>=0 && i<n)
							{
								b[i][k]++;
								i = i-p1[c];
							}
							i = k;
							i = i+p2[c];
							while(i>=0 && i<m)
							{
								b[j][i]++;
								i = i+p2[c];
							}
							break;
						case 3:
							b[j][k]++;
							i = k;
							i = i+p1[c];
							while(i>=0 && i<m)
							{
								b[j][i]++;
								i = i+p1[c];
							}
							i = j;
							i = i+p2[c];
							while(i>=0 && i<n)
							{
								b[i][k]++;
								i = i+p2[c];
							}
							break;
						case 4:
							b[j][k]++;
							i = j;
							i = i+p1[c];
							while(i>=0 && i<n)
							{
								b[i][k]++;
								i = i+p1[c];
							}
							i = k;
							i = i-p2[c];
							while(i>=0 && i<m)
							{
								b[j][i]++;
								i = i-p2[c];
							}
							break;
						case 5:
							b[j][k]++;
							i = k;
							i = i-p1[c];
							while(i>=0 && i<m)
							{
								b[j][i]++;
								i = i-p1[c];
							}
							i = j;
							i = i-p2[c];
							while(i>=0 && i<n)
							{
								b[i][k]++;
								i = i-p2[c];
							}
							break;
					}//switch
				}//if
			}
		}
		for(j = 0;j < n;j++)
		{
			for(k = 0;k < m;k++)
			{
				a[j][k] = b[j][k]%2;
				if(a[j][k] == 1)
					count1[cnt]++;
				//printf("%d\t",a[j][k]);
			}
			
			//printf("\n");
		}
		count1[cnt] += count1[cnt-1];
		tempval = makenum(n,m);
		//rem = tempval%fmod;
		/*for(l = 1; l <= num[rem][0].d; l++)
		{
			if(tempval == num[rem][l].d)
			{
				rot = num[rem][l].idx;
				break;
			}
		}*/
		for(l = 0;l < ctemp;l++)
		{
			if(temp[l] == tempval)
			{
				rot = l;
				break;
			}
		}
		if(rot == -1)
		{
			temp[ctemp] = tempval;
			ctemp++;
			//num[rem][0].d++;
			//assert(num[rem][0].d <100);
			//num[rem][num[rem][0].d].d = tempval;
			//num[rem][num[rem][0].d].idx = cnt;
			cnt++;
		}
		
	}
	mod = cnt-rot;
	sumdiff = count1[cnt-1] - (rot?count1[rot-1]:0);
	for(i = 0;i < q;i++)
	{
		val = readInt();
		if(val>=cnt)
		{
			rat = (val-rot) / mod;
			
			ans = (val - rot)%mod + rot;
			ressum = sumdiff*rat + count1[ans] + (rot?count1[rot-1]:0);
		}
		else
		{
			ans = val;
			ressum = count1[ans];
		}
		printf("%lld\n",ressum);
	}
	//printf("%d %d\n",cnt,rot);
	//}}}}
	/*neeche:
	if(cnt <4000)
	{
		printf("\ngood\n");
	}*/
	return 0;
}
