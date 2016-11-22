#include <iostream>
using namespace std;
int main()
{
	long long int n,q,i,j,temp,qu,t,k,gc,p[100000];
	int cp = 0,cnt;
	cin>>n;

	
	cin>>qu;
	
	for(i = 0;i < qu;i++)
	{
		cin>>t>>k;
		cnt = 0;
		for(j = 1;j <= n;j++)
		{
			if((n%j==0) && (j%k!=0))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
