#include <cstdio>

int main()
{
	char s[170001];
	fread(s,170000,1,stdin);
	printf("%s\n",s);
}
