#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
 
char s[20], m[20];
int n, p, col;
int a[20], b[20];
int c[20][20];
int d[20][20][2][2];
int w[20][20][2][2];
 
int dfs(int u, int v, int gr, int nz)
{
	if (u == n) return 0;
	if (w[u][v][gr][nz] == col) return d[u][v][gr][nz];
	w[u][v][gr][nz] = col; d[u][v][gr][nz] = -1;
 
//	printf("Here u=%d v=%d gr=%d b[v]=%d\n", u, v, gr, b[v]);
 
	for (int i = 9; i >= 0; i--)
	{
	 	if (!i && v==p && !nz) continue;
	 	if (!c[b[v]][i]) continue;
	 	if (!gr && i>a[u]) continue;
 
//		printf("Here u=%d v=%d gr=%d -> %d b[v]=%d --- %d\n", u, v, gr, i, b[v], gr||i<a[u]);
		int x = dfs(u+1, v+1, gr||i<a[u], nz||i>0);
 
		if (x!=-1)
		{
			int val = i;
			for (int j = 0; j < n-u-1; j++)
				val*=10;
			d[u][v][gr][nz] = val+x;
			break;
		}
	}
 
	return d[u][v][gr][nz];
}
 
int main()
{
	for (int i = 0; i < 10; i++)
	{
	 	c[i][i] = 1;
	 	c[10][i] = 1;
	}
	c[0][8] = 1;
	c[1][0] = c[1][3] = c[1][4] = c[1][7] = c[1][8] = c[1][9] = 1;
	c[2][8] = 1;
	c[3][8] = c[3][9] = 1;
	c[4][8] = c[4][9] = 1;
	c[5][6] = c[5][8] = c[5][9] = 1;
	c[6][8] = 1;
	c[7][0] = c[7][3] = c[7][8] = c[7][9] = 1;
	c[9][8] = 1;
 
	int t;
	cin >> t;
	for (; t--;)
	{
	 	scanf("%s%s", s, m);
	 	int res = atoi(s);
	 	int l2 = strlen(s);
	 	n = strlen(m);
 
	 	for (int i = 0; i < n; i++)
	 		a[i] = m[i]-'0';
	 	for (int i = 0; i < 20; i++) b[i] = 10;
	 	for (int i = n-l2; i < n; i++)
	 		b[i] = s[i-n+l2]-'0';
 
	 	p = n-l2;
 
	 	col++;
	 	for (int i = 0; i <= n-l2; i++)
//	 		printf("%d\n", dfs(0, i, 0, 0)),
	 		res = max(res, dfs(0, i, 0, 0));
 
	 	printf("%d\n", res);
	}
 
	return 0;
}
