#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 100000000
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int two(string n)
{
	
}

int main()
{
	char s[100004];
	scanf("%s",s);
	int a = 0;
	int l = strlen(s);
	int f;
	if(l==1)
		f = 0;
	else 
	
		f = (s[l-2]-'0');
	int se = s[l-1]-'0';
	int r = (f*10+se)%4;
	
	int m = 2*r%4;
	if(r==1)
	{
		a+=0;
	}
	if(r==2)
	{
		a+=3;
	}
	if(r==3)
		a+=0;
	if(r==0)
	{
		a+=2;
	}
	if(m==1)
	{
		a+=2;
	}
	if(m==2)
	{
		a+=4;
	}
	if(m==3)
		a+=3;
	if(m==0)
	{
		a+=1;
	}
	a+=1;
	printf("%d",a%5);
	return 0;
}
