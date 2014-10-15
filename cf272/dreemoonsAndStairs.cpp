/*
 dreemoonsAndStairs.cpp
 Author: shashwat001
 Created on: 2014-10-13 22:46
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cassert>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int minsteps = (n+1)/2;
	if(n < m)
	{
		printf("-1");
		return 0;
	}
	minsteps = max(minsteps,m);
	int i = (minsteps-1)/m;
	//int steps = (i+1)*m;
	//printf("%d\n",(i+1)*m );
	i = m;
	while(i < minsteps)
	{
		i+=m;
	}
	if(i <= n)
	printf("%d\n", i);
	else printf("-1");
			
	return 0;
}

