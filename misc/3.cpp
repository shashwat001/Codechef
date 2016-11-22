#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int i,j,k,l,cs = 0,f;
int a[1000],b[256] = {0};
char s[500005],out[500005];
int main()
{
	cin>>f;
	cin>>k;
	cin>>s;
	i = 1;
	min1 = 0;
	min2 = 0;
	changed = 0;
	out[0] = s[0];
	while(i<=f)
	{
		if(s[i] == out[i-1])
		{
			if(changed==0)
			{
				out[i] = (s[i-1]-65)+1%k + 64;
				min1 = min2;
				min2 = min2+1;
				changed = 1;
			}
			else
			{
				if(k==2)
				{
					out[i] = (out[i-1]-65)+1%k + 64;
				}
			}
		}
	}
	return 0;
}
