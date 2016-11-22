#include <stdio.h>

#define min(a,b) (a)>(b)?(b):(a)
long long int triangle[1000][1000];

long long int run(int n) 
{

	int i,j,k;
	// Calculate cumulative sums for each row
	long long int rowSums[1000][1000];
	for ( i = 0; i < n; i++) 
	{
		rowSums[i][0] = 0;
		for ( j = 0; j <= i; j++)
			rowSums[i][j + 1] = rowSums[i][j] + triangle[i][j];
	}

	// Calculate minimum subtriangle sum for each apex position
	long long int minSum = 1000000000000000000LL;
	for ( i = 0; i < n; i++) 
	{
		for ( j = 0; j <= i; j++) 
		{
			
			long long int curSum = 0;
			for ( k = i; k < n; k++) 
			{ 
				curSum += rowSums[k][k - i + 1 + j] - rowSums[k][j];
				minSum = min(curSum, minSum);
			}
		}
	}
	return minSum;
}


	int main()
	{
		
		int n,i,j;
		scanf("%d",&n);
		for (i = 0; i < n; i += 1)
		{
			for (j = 0; j <= i; j += 1)
			{
				scanf("%lld",&triangle[i][j]);
			}
		}
		printf("%lld",run(n));
		return 0;
	}
