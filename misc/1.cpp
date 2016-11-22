#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int i,j,k,l,cs = 0,f;
int a[1000],b[256] = {0};
char s[1005];
int main()
{
	cin>>k;
	cin>>s;
	l = strlen(s);
	if(l%k != 0)
	{
		cout<<-1;
		return 0;
	}
	f = l/k;
	for(i = 0;i < l;i++)
	{
		b[s[i]]++;
	}
	for(i = 0;i < 256;i++)
	{
		if(b[i] % k != 0)
		{
			cout<<-1;
			return 0;
		}
	}
	for(i = 0;i < 256;i++)
	{
		if(b[i])
		{
			j = b[i]/k;
			while(j>0)
			{
				s[cs++] = i;
				j--;
			}
		}
	}
	s[cs] = '\0';
	for(i = 0;i <k;i++)
	{
		cout<<s;
	}
	
	
	
	return 0;
}
