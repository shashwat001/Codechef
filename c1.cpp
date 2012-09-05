#include <queue>
#include <cstdio>

using namespace std;

queue<char *> q;

int main()
{
	int n;
	char c;
	scanf("%d",&n);
	scanf("%c",&c);
	if(c=='Q')
		return 0;
	if(c=='A')
	{
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",str);
			q.push(str);
		}
	}		
	if(c=='R')
	{
		scanf("%d",&m);
		while(m--)
		{
			q.pop();
		}
	}	
	return 0;
}
