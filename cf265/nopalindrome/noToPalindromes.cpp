#include <bits/stdc++.h>

using namespace std;

bool nextString(char str[],int p)
{
	int l = strlen(str);
	int carry = 0;
	for(int i = l-1;i >= 0;i--)
	{
		str[i] = str[i] + 1 + carry;
		if(str[i] > 'a' + p)
		{
			str[i] = str[i] - ('a'+p);
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		
	}
	if(carry == 1)
		return false;
	return true;
}

int main()
{
    freopen("input.txt","r", stdin);
	char s[1004];
    int p,l;
	cin>>l>>p;
	cin>>s;
    while(nextString(s,p))
    {
        bool ans = true;
        if(l>1) {
            if (s[l - 1] == s[l - 2])
                ans = false;
        }
        if(l>2)
            if(s[l-1] == s[l-3] || s[l-2]==s[l-3])
                ans = false;
        if(ans == true)
        {
            cout<<s;
            return 0;
        }

    }
    cout<<"NO";
    return 0;
}

