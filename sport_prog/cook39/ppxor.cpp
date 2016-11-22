#include <bits/stdc++.h>

using namespace std;
long long int t,n,i;
long long int a[35][100006];
long long int output = 0;

void input()
{
			long long int x;
			scanf("%lld",&x);
			long long int j = 0;
			while(x>0)
			{
				a[j][i] = x&1;
				x>>=1;
				j++;
			}
}

void calcout()
{
			long long int sum = 0,even = 1,odd = 0;
			for (unsigned int j = 0; j < n; j += 1)
			{
				sum = (sum+a[i][j])%2;
				if(sum==0)
					even++;
				else
					odd++;
			}
			output = output + (even*odd)*(1<<i);
}
int main ()
{
    
	cin>>t;
	while(t--)
	{
        
		scanf("%lld",&n);
		for(i = 0;i < 35;i++)
		{
			for (unsigned int j = 0; j < n+10; j += 1)
			{
				a[i][j] = 0;
			}
		}
		for(i = 0;i < n;i++)
		{
			input();
		}
					output = 0;
		for(i = 0;i < 32;i++)
		{

			calcout();
		}
		cout<<output<<endl;
		
	}
	return 0;
}
