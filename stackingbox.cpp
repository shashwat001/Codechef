#include <cstdio>
#include <vector>
#include <utility>

#define INF 2000000000

void inorder(int &a,int &b,int &c)
{
	int t;
	if(c>=a && c>=b)
	{
		if(b>=a)
			return;
		else
		{
			t = a;
			a = b;
			b = t;
			return;
		}
	}
	else if(b>=a && b>=c)
	{
		t = c;
		c = b;
		b = t;
		if(b>=a)
			return;
		else
		{
			t = a;
			a = b;
			b = t;
			return;
		}
	}
	else
	{
		t = c;
		c = a;
		a = t;
		if(b>=a)
			return;
		else
		{
			t = a;
			a = b;
			b = t;
			return;
		}
	}
}

vector<pair<int,int> > a;
int main()
{
	int i,j,a,b,c,n;
	pair<int,int> base = make_pair(INF,INF);
	scanf("%d",&n);
	while(n)
	{
		a.push_back(base);
		sz = 0;
		h = 0;
		for(i = 1;i <= n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			inorder(a,b,c);
			idx = bins(a,b);
		}
	}
	return 0;
}
