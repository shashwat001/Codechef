#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define make_pair mp
#define push_back pb

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int i,j;

int main()
{
	long long int ax,ay,bx,by,cx,cy,m,n;
	//scanf("%l64d %l64d %l64d %l64d %l64d %l64d",&ax,&ay,&bx,&by,&cx,&cy);
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	m = (cy-ay)*(bx-ax);
	n = (cx-ax)*(by-ay);
	if((m)==(n))
	{
		printf("TOWARDS");
		return 0;
	}
	if(((bx-ax)*(cy-by)-(cx-bx)*(by-ay)) < 0)
	{
		printf("RIGHT");
	}
	else
	{
		printf("LEFT");
	}
	return 0;
}
