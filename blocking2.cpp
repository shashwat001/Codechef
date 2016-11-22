#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

#define INF 2147483647

using namespace std;

int main()
{
	int n,i,j,a[100][100],men[100] = {0},women[100] = {0},pairw[100],pairm[100],pr[100][100],w,id,k,there[100] = {0};
	scanf("%d",&n);
	vector<pair<int,int> > vm[100],vf[100];
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			scanf("%d",&k);
			a[i][j] = k;
			vm[i].push_back(make_pair(k,j));
			vf[j].push_back(make_pair(k,i));
		}		
	}
	memset(pr,0,sizeof(pr));
	for(i = 0;i < n;i++)
	{
		sort(vm[i].begin(),vm[i].end());
		sort(vf[i].begin(),vf[i].end());
	}
	while(1)
	{
		for(i = 0;i < n;i++)
		{	
			if(men[i] == 0)
			{
				for(j = 0;j < n;j++)
				{
					w = vm[i][j].second;
					if(pr[i][w]==0)
						break;
				}
				if(j!=n)
					break;
			}
		}
		if(i==n)	
			break;
		pr[i][w] = 1;
		if(women[w] == 0)
		{
			pairm[i] = w;
			pairw[w] = i;
			women[w] = 1;
			men[i] = 1;
			
		}
		else
		{
			id = pairw[w];
			if(a[id][w]<a[i][w])
			{
				pairm[i] = w;
				pairw[w] = i;
				men[id] = 0;
				men[i] = 1;
			}
		}
		
	}
	for(i = 0;i<n-1;i++)
	{
		printf("%d ",pairm[i]+1);
	}
	printf("%d ",pairm[i]+1);

	return 0;
}
