#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,i,l,a[30];
	char str[1000];
	cin>>n;	
	cin.getline(str,400);
	while(n--)
	{
		memset(a,0,sizeof(a));
		cin.getline(str,400);
		l = strlen(str);
		for(i = 0;i < l;i++)
		{
			if(str[i] >= 'a' && str[i]<='z')
			{
				a[str[i]-'a']++;
			}
			else if(str[i] >= 'A' && str[i]<='Z')
			{
				a[str[i]-'A']++;
			}
		}
		for(i = 0;i < 26;i++)
		{
			if(a[i] == 0)
			{
				printf("%c",i+'A');
				break;
			}
		}
		if(i == 26)
			printf("~");
		printf("\n");
	}
	return 0;
}
