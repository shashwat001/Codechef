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

int main ()
{
	int t,i,j,a[105],p[105],n;
	float sum[100][10005] ;
	int totsum = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		totsum = 0;
		memset(sum,0.0,sizeof(sum));
		sum[0][0] = 1.0;
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			totsum+=a[i];
		}
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i = 1;i <= n;i++)
		{
			sum[i][0] = (sum[i-1][0]*(100-p[i]))/100;
			for(j = 1;j <= totsum;j++)
			{
				if(j<a[i])
				{
					sum[i][j] = (sum[i-1][j]*(100-p[i]))/100;
					continue;
				}
				sum[i][j] = (sum[i-1][j]*(100-p[i]))/100+(p[i]*sum[i-1][j-a[i]])/100;
			}
//			for(j = 0;j <= totsum;j++)
//			{
//				printf("%f\t",sum[i][j]);
//			}
//			cout<<endl;
		}
		int half = (totsum+1)/2;
		float totprob = 0.0;
		for(i = half;i <= totsum;i++)
		{
			totprob += sum[n][i];
		}
		printf("%f\n",totprob);
	}
	return 0;
}
