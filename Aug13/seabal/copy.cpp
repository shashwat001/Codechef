#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace::std;

#define MAX 100000

struct node
{
	int index;
	int val;

	node *prev;
	node *next;
};

int num_vals(vector<int> &v, int a, int b)
{
	if (v.size() == 0)
		return 0;

	if (v.front() > b)
		return 0;

	if (v.back() < a)
		return 0;

	int low = -1;
	if (v.front() >= a)
		low = 0;
	else
	{
		int beg = 0;
		int end = v.size() - 1;

		while ((end - beg) > 1)
		{
			int mid = (beg + end) / 2;
			if (v[mid] < a)
				beg = mid;
			else
				end = mid;
		}

		low = end;
	}
	
	int high = -1;
	if (v.back() <= b)
		high = v.size() - 1;
	else
	{
		int beg = 0;
		int end = v.size() - 1;

		while ((end - beg) > 1)
		{
			int mid = (beg + end) / 2;
			if (v[mid] <= b)
				beg = mid;
			else
				end = mid;
		}

		high = beg;
	}

	return (high - low + 1);
}

main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	vector<node*> nodes(N);
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);

		nodes[i] = new node;
		nodes[i]->index = i;
		nodes[i]->val = x;
	}

	for (int i = 0; i < N; i++)
	{
		if (i > 0)
			nodes[i]->prev = nodes[i - 1];
		else
			nodes[i]->prev = 0;

		if (i < (N - 1))
			nodes[i]->next = nodes[i + 1];
		else
			nodes[i]->next = 0;
	}

	vector<vector<int> > X(MAX, vector<int>());
	vector<vector<int> > Y(MAX, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);

		a--;
		b--;

		X[a].push_back(b);
		Y[b].push_back(a);
	}

	for (int i = 0; i < MAX; i++)
	{
		std::sort(X[i].begin(), X[i].end());
		std::sort(Y[i].begin(), Y[i].end());
	}

	set<int> covered = set<int>();

	int T;
	scanf("%d", &T);

	int ans = 0;
	for (int t = 0; t < T; t++)
	{
		int k;
		scanf("%d", &k);
		
		k += ans;
		k--;

		if (!nodes[k])
		{
			printf("%d\n", ans);
			continue;
		}

		nodes[k]->val--;
		if (nodes[k]->val > 0)
		{
			printf("%d\n", ans);
			continue;
		}

		int curr = nodes[k]->index;
		int s = 0;
		int e = N - 1;

		if (nodes[k]->prev)
		{
			s = 1 + nodes[k]->prev->index;
			nodes[k]->prev->next = nodes[k]->next;
		}

		if (nodes[k]->next)
		{
			e = nodes[k]->next->index - 1;
			nodes[k]->next->prev = nodes[k]->prev;
		}

		// mem leak
		nodes[k] = 0;

		int x1 = s;
		int x2 = curr;

		int y1 = curr;
		int y2 = e;

		bool row_scan = true;
		set<int>::iterator it = covered.lower_bound(x1);
		if (it != covered.end())
		{
			if ((*it) <= x2)
				row_scan = false;
		}

		int t = 0;
		if (row_scan)
		{
			for (int x = x1; x <= x2; x++)
			{
				t += num_vals(X[x], y1, y2);
				covered.insert(x);
			}
		}
		else
		{
			for (int y = y1; y <= y2; y++)
				t += num_vals(Y[y], x1, x2);
		}

		ans += t;
		printf("%d\n", ans);
	}
}
