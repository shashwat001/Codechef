#include <stdio.h>
int main()
{
	int n,m,min,i,l,r;
	int a[100002];
	scanf("%d",&m);
	for(i = 0;i < m;i++)
		scanf("%d",&a[i]);

	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&l,&r);
		min = a[l];
		for(i = l+1;i<=r;i++)
		{
			if(min < a[i])
				min = a[i];
		}
		printf("%d\n",min);
	}
	return 0;
}
