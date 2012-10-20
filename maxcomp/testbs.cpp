#include <cstdio>
int a[100];
int bs(int left, int right, int val)
{
	if(right < 0)
		return -1;
	if(left == right)
	{
			return (left-1);
	}
	int res;
	int mid = (left+right)>>1;
	if(a[mid] < val)
		res = bs(mid+1,right,val);
	else
		res = bs(left,mid,val);
	return res;
}
int main()
{
	int n,i,val;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&val);
	printf("%d\n",bs(0,n-1,val));
	return 0;
}
