#include <bits/stdc++.h>

using namespace std;

int main()
{
	int p[10005][27];
	int i,l,a[10005],ca,maxcnt[10005][2],sumc,cm,maxv,j,t,maxleftarr[10005],maxrightarr[10005],maxprevarr[10005],maxnextarr[10005],maxleft,maxright,maxprev,maxnext,diff;
	char s[10005];
	
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%s",s);
		l = strlen(s);
		memset(maxcnt,0,sizeof(maxcnt));
		maxleft = 0;
		for(i = 0;i < l;i++)
		{
			maxleftarr[i] = maxleft;
			if(s[i] == '#')
			{
				maxprev = 0;
				for(j = 0;j < 26;j++)
				{
					diff = maxcnt[j][1] - maxcnt[j][0];
					if(diff>maxprev)
					{
						maxprev = diff;
					}
					maxcnt[j][0] = maxcnt[j][1];
				}
				maxprevarr[i] = maxprev;				
			}
			else
			{
				maxcnt[s[i]-'a'][1]++;
				if(maxcnt[s[i]-'a'][1]>maxleft)
				{
					maxleft = maxcnt[s[i]-'a'][1];
					
				}
			}
			
		}
		memset(maxcnt,0,sizeof(maxcnt));
		maxright = 0;
		for(i = l-1;i >= 0;i--)
		{
			maxrightarr[i] = maxright;
			if(s[i] == '#')
			{
				maxnext = 0;
				for(j = 0;j < 26;j++)
				{
					diff = maxcnt[j][1] - maxcnt[j][0];
					if(diff>maxnext)
					{
						maxnext = diff;
					}
					maxcnt[j][0] = maxcnt[j][1];
				}
				maxnextarr[i] = maxnext;				
			}
			else
			{
				maxcnt[s[i]-'a'][1]++;
				if(maxcnt[s[i]-'a'][1]>maxright)
				{
					maxright = maxcnt[s[i]-'a'][1];
					
				}
			}
			
		}
		ca = 0;
		memset(a,0,sizeof(a));
		for(i = 0;i < l;i++)
		{
			if(s[i]=='#')
				a[ca++] = i;
		}
		maxv = 0;
		for(i = 0;i < ca-2;i++)
		{
			if(maxleftarr[a[i]]==0 || maxprevarr[a[i+1]]==0 || maxprevarr[a[i+2]]==0 || maxrightarr[a[i+2]]==0)
			{
				sumc = 0;
			}
			else
			{
				sumc = maxleftarr[a[i]]+maxprevarr[a[i+1]]+maxprevarr[a[i+2]]+maxrightarr[a[i+2]] + 3;
			}
			if(sumc>maxv)
				maxv = sumc;
		}
		printf("%d\n",maxv);
	}	
	return 0;
}
