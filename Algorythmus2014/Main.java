public class Main
{
typedef long long int lli;
typedef pair<int,int> pi;
	char r[200][200];
public static void main (Strings[] args)
{

	int cr,cc,i,k;
	cin>>cr>>cc;
	int cnt = 0;
	char s[20] = "alela",S[20] = "ALELA";
	for(i = 0;i < cr;i++)
	{
		cin>>r[i];
		for (unsigned int j = 0; j < cc-4; j += 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[i][j+k] != s[k] ) && (r[i][j+k] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	for(i = 0;i < cc;i++)
	{
		for (unsigned int j = 0; j < cr-4; j += 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[j+k][i] != s[k]) && (r[j+k][i] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	
	for(i = 0;i < cr-4;i++)
	{
		for (unsigned int j = 0; j < cc-4; j += 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[i+k][j+k] != s[k]) && (r[i+k][j+k] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	for(i = 0;i < cr-4;i++)
	{
		for (unsigned int j = cc-1; j >= 4; j -= 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[i+k][j-k] != s[k]) && (r[i+k][j-k] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	cout<<cnt*2<<endl;
}
