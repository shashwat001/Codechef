#include <cstdio>
#include <cstring>

int main()
{
	int t,n,i,tot;
	char s[1001];
	scanf("%d",&t);
	while(t--)
	{
		tot = 0;
		scanf("%d",&n);
		scanf("%s",s);
		if((n==1) && (s[0]=='0'))
		{
			tot = 1;
		}
		else
		{
			for(i = 1;i < (n-1);i++)
			{
				if((s[i-1]=='0')&& (s[i]=='0') && (s[i+1]=='0'))
					tot++;
			}
			
			if(s[0] == '0' && s[1] == '0')
				tot++;
			if(s[n-1] == '0' && s[n-2] == '0')
				tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}
