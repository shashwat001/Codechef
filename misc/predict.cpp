#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	double x,p,m,n,ans;
	scanf("%d", &t);

	while(t--)
	{
		
		scanf("%lf", &x);
		p = (double) ((int) (x * 100000 + 0.001)) / 100000;
		m = 10000 * p * (3.0 - 2.0 * p);
		n = 10000 * (1.0 - p) * (1.0 + 2.0 * p);

		ans = (m > n) ? m : n;
		printf("%lf\n",ans);
	}
	return 0;
}
