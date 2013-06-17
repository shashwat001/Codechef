#include <bits/stdc++.h>

int main()
{
	int n = rand()%100+1;
	printf("%d\n",n);
	for(int i = 0; i < n;i++)
	{
		char s[10006];
		int l = rand()%50+1;
		for(int j = 0;j < l;j++)
		{
			int p = rand()%100+1;
			if(p <= 30)
			{
				s[j] = '#';
			}	
			else
			{
				s[j] = rand()%26 + 'a';
			}
		}
		s[l] = '\0';
		printf("%s\n",s);
	}
	return 0;
}
