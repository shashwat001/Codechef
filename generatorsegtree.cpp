#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

int main()
{
	srand(time(NULL));
	int m = rand()%1000+2;
	int a,b,i,j,l,r;
	printf("%d\n",m);
	for(j = 0;j < m;j++)
	{
		i = rand()%10000000;
		printf("%d\n",i);
	}
	
	int n= rand()%10000+2;
	
	printf("%d\n",n);
	for(i = 0;i < n;i++)
	{
		r = rand()%(m-1)+1;
		l = rand()%r;
		printf("%d %d\n",l,r);
		
	}
	

	return 0;
}
