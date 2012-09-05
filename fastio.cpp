#include <cstdio>
void readstr(char *str)
{
	int count = 1,i = 0;
	char c;
	fread(&c,1,count,stdin);
	while(c!='\n' && c!=' ')
	{
		str[i++] = c;
		fread(&c,1,count,stdin);
	}	
	str[i] = '\0';
}



int main()
{
	char c;
	char str[50];
	int t = 1;
	while(t--)
	{
	readstr(str);
	printf("%s\n",str);
	}
	return 0;
}
