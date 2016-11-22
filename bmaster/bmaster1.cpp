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

int i,j,temp[50000][34][34];

int main()
{
	int n,m,p,q,x,y,k,c,p1[6],p2[6],a[34][34],b[34][34],z,ctemp,rot = -1,cnt,l,count1[50000],mod,ans,ercnt = 0;
	lli val;
	for(n = 1;n <= 34;n++){
	for(m = 1;m <= 34/n;m++){
	//n = readInt();
	//m = readInt();
	//q = readInt();
	for(x = 1;x <= n;x++){
	for(y = 1;y <= m;y++){
	//x = readInt();
	//y = readInt();
	for(i = 0;i < 6;i++)
	{
		//p1[i] = readInt();
		p1[i] = 1;
		p2[i] = 1;
		//p2[i] = readInt();
	}
	
	memset(a,0,sizeof(a));
	memset(temp[0],0,sizeof(temp[0]));
	a[x-1][y-1] = 1;
	temp[0][x-1][y-1] = 1;
	ctemp = 1;
	memset(count1,0,sizeof(count1));
	count1[0] = 1;
	/*for(j = 0;j < n;j++)
	{
		for(k = 0;k < m;k++)
		{
			printf("%d\t",a[j][k]);
		}
		printf("\n");
	}
	printf("\n\n\n");*/
	cnt = 1;
	rot= -1;
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
		if(count1[cnt] == 0) 
		{
			cout << "error\n";
			cout <<n<<" "<<m<<" "<<x<<" "<<y<<endl;
			ercnt++;
			if(ercnt==10)
				exit(0);
		}
		count1[cnt] += count1[cnt-1];
		for(l = 0;l < ctemp;l++)
		{
			for(j = 0;j < n;j++)
			{
				for(k = 0;k < m;k++)
				{
					if(temp[l][j][k] != a[j][k])
						break;
				}
				if(k!=m)
					break;
			}
			if(j==n)
			{
				rot = l;
				break;
			}
		}
		if(rot == -1)
		{
			for(j = 0;j < n;j++)
			{
				for(k = 0;k < m;k++)
				{
					temp[ctemp][j][k] = a[j][k];
				}
			}
			ctemp++;
			cnt++;
		}
	}
		//printf("\n\n\n");
	}}}}	
	//}	
	return 0;
}
