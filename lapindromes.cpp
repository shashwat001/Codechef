#include <bits/stdc++.h>

int main()
{
	char s[1005];
	int i,t,a[26],b[26],l;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%s",s);
		l = strlen(s);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i = 0;i < l/2;i++)
		{
			a[s[i]-'a']++;
			b[s[l-1-i]-'a']++;
		}
		for(i = 0;i < 26;i++)
		{
			if(a[i]!=b[i])
				break;
		}
		if(i==26)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
	
}

