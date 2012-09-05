#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>

#define INF 2147483647
#define LLINF 9223372036854775807
#define make_pair mp
#define push_back pb


int i,j;

int main()
{
	int n,a[100011],count=  0,idx[5];
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		if(i == 0)
			continue;
		if(a[i] < a[i-1])
		{
			idx[count] = i;
			count++;
			
		}
	}
	if(count>2)
	{
		printf("NO");
		return 0;
	}
	if(count == 2)
	{
		if(idx[1]!=n-1)
		{
		if(a[idx[1]] >= a[idx[0]-1] && a[idx[1]]<= a[idx[0]+1] && a[idx[0]] >= a[idx[1]-1] && a[idx[0]]<= a[idx[1]+1])
			printf("YES");
		else
			printf("NO");
		}
		else
				{
		if(a[idx[1]] >= a[idx[0]-1] && a[idx[1]]<= a[idx[0]+1] && a[idx[0]] >= a[idx[1]-1])
			printf("YES");
		else
			printf("NO");
		}
		return 0;
	}
	return 0;
}
