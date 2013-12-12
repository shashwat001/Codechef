//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

#define BUF 4096
char ibuf[BUF]; 
int ipt = BUF;
 
long long int readInt() 
{ 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++; 
    }
    long long int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) 
    {
		fread(ibuf, 1, BUF, stdin);
	 
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0'); 
    }
    return n;
}
 

string preProcess(string s) {
  int n = 32;
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s[i];
 
  ret += "#$";
  return ret;
}
 
int longestPalindrome(char T[]) {
	//string s(a);
  int n = 67;
  int P[100];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  	return maxLen;
  //string out =  s.substr((centerIndex - 1 - maxLen)/2, maxLen);
  //return out.size();
}

int main ()
{
	int t,n,i;
	t = readInt();
	char a[100];
	while(t--)
	{
		n = readInt();
		for(i = 0;i < 32;i++)
		{
			a[2*i+2] = (char)((n&1) + 97);
			a[2*i+1] = '#';
			n >>= 1;
		}
		a[0] = '^';
		a[65] = '#';
		a[66] = '$';
		a[67] = '\0';
		printf("%d\n",longestPalindrome(a));
	}
	
	return 0;
}
