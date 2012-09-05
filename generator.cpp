#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

int main()
{
	srand(time(NULL));
	//int t = rand()%20 + 1;
	int t = 200,i,j;
	int n,m,w,x,y,z = 10000,done[10000];
	char str[10001];
	n = 100;
	printf("%d\n",n);
	//while(t--)
	//{
		
		for(i = 0;i<n;i++)
		{
			memset(done,0,sizeof(done));
			for(j = 0;j < n;j++)
			{
				w = rand()%z;
				if(done[w]==0)
				{
					printf("%d ",w);
					done[w] = 1;
				}
				else
					j--;
			}
			printf("\n");
		}
	//}
	return 0;
}
