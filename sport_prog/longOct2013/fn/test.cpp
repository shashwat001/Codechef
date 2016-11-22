#include <iostream>

using namespace std;
int a[10000007] = {0};
int b[10000007];
int cb = 0,i,j;
int main()
{
	for(i = 3;i <= 10000000;i++)
	{
		if(a[i])
			continue;
		if((i%10 ==1 )|| (i%10==9))
			b[cb++] = i;
		for(j = 2*i;j <= 10000000;j+=i)
		{
			a[j] = 1;
		}
	
	}
	for(i = 0;i < 100;i++)
	{
		cout<<b[i]<<" ";
	}
	a[0] = 0;
	a[1] = 1;
	for(i = 2;i <= 10000000;i++)
	{
		a[i] = a[i-1]+a[i-2];
	}
	for(i = 0;i < 1000;i++)
	{
		for(j = 1;)
	}
	return 0;
}
