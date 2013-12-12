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
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

void copyfunc(int src[][16],int dest[][16],int n,int m)
{
	for(int ii = 0;ii < n;ii++)
	{
		for (int jj = 0; jj < m; jj += 1)
		{
			dest[ii][jj] = src[ii][jj];
		}
	}
}

void fillbelow(int arr[][16],int i,int j,int limit)
{
	int tempi = i+1;
	while(tempi < limit && arr[tempi][j] != 2)
	{
		arr[tempi][j] = 2;
		tempi++;
	}
}
void fillabove(int arr[][16],int i,int j,int limit)
{
	int tempi = i-1;
	while(tempi >= limit && arr[tempi][j] != 2)
	{
		arr[tempi][j] = 2;
		tempi--;
	}
}

void fillright(int arr[][16],int i,int j,int limit)
{
	int tempj = j+1;
	while(tempj < limit && arr[i][tempj] != 2)
	{
		arr[i][tempj] = 2;
		tempj++;
	}
}

void fillleft(int arr[][16],int i,int j,int limit)
{
	int tempj = j-1;
	while(tempj >= limit && arr[i][tempj] != 2)
	{
		arr[i][tempj] = 2;
		tempj--;
	}
}


int minimax(int board[16][16],int move,int n,int m, stack<int> stk)
{
	int res = 0;
	int tempboard[16][16];
	int i,j;
	while(!stk.empty())
	{
		pair<int,int> temppair = stk.top();
		i = stk.first;
		j = stk.second;
		if(board[i][j]==1)
		{
			//copyfunc(board,tempboard,n,m);			
			for(int ii = 0;ii < n;ii++)
			{
				for (int jj = 0; jj < m; jj += 1)
				{
					tempboard[ii][jj] = board[ii][jj];
				}
			}
			tempboard[i][j] = 2;
			fillbelow(tempboard,i,j,n);				
			fillabove(tempboard,i,j,0);
			fillright(tempboard,i,j,m);
			fillleft(tempboard,i,j,0);
		
			if(move&1)
			{
				res = max(res,minimax(tempboard,move+1,n,m));
				if(res == 1)
					return res;
			}
			else
			{
				res = min(res,minimax(tempboard,move+1,n,m));
				if(res == -1)
					return res;
			}
		}
	}
	if(move&1)
		return -1;
	return 1;
}


int main()
{
	int n,m,i,j;
	char s[21][25];
	int board[16][16] = {0};
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i++)
	{
		scanf("%s",s[i]);
	}
	for(i = 2;i < n-2;i++)
	{
		for (j = 2; j < m-2; j += 1)
		{
			if(s[i][j]=='^')
			{
				if(s[i-1][j]=='^' && s[i-2][j]=='^' &&
					s[i+1][j]=='^' && s[i+2][j]=='^' &&
					s[i][j-1]=='^' && s[i][j-2]=='^' &&
					s[i][j+1]=='^' && s[i][j+2]=='^' )
					{
						board[i-2][j-2] = 1;
						stk.push(mp(i-2,j-2));
					}
			}
		}
	}
	n = n-4;
	m = m-4;
	int res = minimax(board,1,n,m,stk);
	if(res==1)
		cout<<"first"<<endl;
	else
		cout<<"second"<<endl;
	return 0;
}
