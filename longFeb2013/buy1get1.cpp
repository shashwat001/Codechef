#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int t,sum,i;
	cin>>t;
	char s[202];
	int a[258];
	while(t--)
	{
		sum = 0;
		memset(a,0,sizeof(a));
		cin>>s;
		i = 0;
		while(s[i]!='\0')
		{
			a[s[i]]++;
			i++;
		}
		for(i = 0;i < 256;i++)
		{
			sum += (a[i]+1)/2;
		}
		cout<<sum<<endl;
	}
	return 0;
}

