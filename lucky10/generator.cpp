#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int l,t;
	srand(time(NULL));
	t = rand()%100+1;
	t = 5;
	printf("%d\n",t);
	while(t--)
	{
		l = rand()%10000+1;
		while(l--)
		{
			printf("%d",rand()%10);
		}
		printf("\n");
		l = rand()%10000+1;
		while(l--)
		{
			printf("%d",rand()%10);
		}
		printf("\n");
	}
}
