#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int pp = 1 ; pp <= T ; pp++) 
	{
		int i;
		long long int N,C,K;
		cin>>N>>C>>K;
		if(C<=N)
		{
				printf("Case #%d: %lld\n",pp,N-C+K);
		} 		
		else
		{
			if(N==1)
			{
					printf("Case #%d: %lld\n",pp,K);
					continue;
			}
			if(N>1)
			{
				if(C%N==0)
				{
					printf("Case #%d: %lld\n",pp,K);
					continue;
				}
				// C  N K
				long long int temp2,temp1,temp = N*(C/N);
				if(K<=temp)
				{
					printf("Case #%d: %lld\n",pp,K);
					continue;
				}
				for (i= 1 ; i < N ; i++)
				{
					temp1 = C % ( N-i);
					temp2 = C/ (N-i);
					if(temp2 < temp1)
					{
						continue;
					}
					else
					{
						printf("Case #%d: %lld\n",pp,K+i);
						break;
					}
				}
			}
		}
		continue;
	}
	return 0;
}
