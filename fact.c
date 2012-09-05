#include <stdio.h>

int main()
{
	int i,f,n;
	f = 1;
	n = 10;
	for(i = 2;i <= n;i++)
		f = f*i;
	printf("%d",f);
	return 0;
}
