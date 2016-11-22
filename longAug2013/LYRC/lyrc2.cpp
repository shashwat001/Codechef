//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
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

int word[5006],F[5000600];

char s[5006000];

void build_failure_function(char pattern[])
{
	int i,j,m = strlen(pattern);

	F[0] = F[1] = 0; // always true

	for(i = 2; i <= m; i++) 
	{
  
		j = F[i - 1];
		while(1)
		{
	 		if(pattern[j] == pattern[i - 1]) 
      		{ 
        		F[i] = j + 1; 
        		break; 
      		}
      		if(j == 0) 
      		{ 
		  		F[i] = 0; 
		  		break; 
      		}
      		j = F[j];
    	}
  	}   
}

int Knuth_Morris_Pratt(char word[])
{
	int n = strlen(s);
	int m = strlen(word);
	build_failure_function(word);


	int j,i = 0,cnt=0; 
	j = 0;
  
	while(1)
	{
    	if(j == n) 
    		break; // we reached the end of the text

		// if the current character of the text "expands" the
		// current match 
		if(s[j] == word[i]) 
		{
			i++; // change the state of the automaton
			j++; // get the next character from the text
			if(i == m) 
				cnt++;
		}
		else
			if(i > 0) i = F[i];
		else j++;
  	}
  	return cnt;
}

char words[501][5006];
int main ()
{
	int n,i,w;
	scanf("%d",&w);
	for(i = 0;i < w;i++)
	{
		scanf("%s",words[i]);
	}
	scanf("%d",&n);
	int length = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%s",&s[length]);
		length = strlen(s);
		if(i<n-1)
		{
			s[length] = ' ';
			length++;
		}
	}
	for(i = 0;i < w;i++)
	{
		printf("%d\n",Knuth_Morris_Pratt(words[i]));
	}
	return 0;
}
