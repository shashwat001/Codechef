#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

#define INF 2147483647

using namespace std;

int main()
{
	int n,i,j,a[100][100],block[100],k,rem[100][100],minj,mink,frnd[100],room[100],minval;
	scanf("%d",&n);
	vector<pair<int,int> > v[100];
	memset(rem,0,sizeof(rem));
	memset(frnd,0,sizeof(frnd));
	memset(room,0,sizeof(room));
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			scanf("%d",&k);
			v[j].push_back(make_pair(k,i));
		}		
	}
	for(i = 0;i < n;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(i = 0;i < n;i++)
	{
		minval = INF;
		for(j = 0;j < n;j++)
		{
			if(room[j] == 1)
				continue;
			for(k = n-1;k>=0;k--)
			{
				if(frnd[v[j][k].second] == 0)
				break;
			}	
			if(v[j][k].first<minval)
			{
				minval = v[j][k].first;
				minj = j;
				mink = v[j][k].second;
			}
		}
		frnd[mink] = 1;
		room[minj] = 1;
		block[mink] = minj+1;
	}
	for(i = 0;i <n;i++)
	{
		printf("%d ",block[i]);
	}
	return 0;
}
