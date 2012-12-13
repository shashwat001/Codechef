#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

int main()
{
	srand(time(NULL));
	int n = rand()%100+2;
	//int n=8;
	int m,a,b,i,j;
	printf("%d\n",n);
	while(n--)
	{
		i = rand()%1000000007;
		printf("%d\n",i);
	}
	
	

	return 0;
}
