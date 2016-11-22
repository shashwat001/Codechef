#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	int j,n,x[6],i;
	double minarea = 100000000.0;
	double maxarea = 0.00;
	int minidx,maxidx;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < 6;j++)
			scanf("%d",&x[j]);

		double area = abs((x[0]*(x[3]-x[5])+ x[2]*(x[5]-x[1])+x[4]*(x[1]-x[3]))/2);
		if(maxarea <= area)
		{
			maxarea = area;
			maxidx = i;
		}
		if(minarea >= area)
		{
			minarea = area;
			minidx = i;
		}
	}
	printf("%d %d",minidx+1,maxidx+1);
	return 0;
}
