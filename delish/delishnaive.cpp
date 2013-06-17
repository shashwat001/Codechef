#include <bits/stdc++.h>

int main()
{
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		for(j = i;j < n;j++)
		{
			sum = 0;
			for(k = i;k <= j;k++)
			{
				sum += a[k];
			}
			c[i][j] = sum;
		}
	}
}
