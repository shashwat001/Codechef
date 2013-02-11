#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace::std;

#define M 524288

void update(int *tree, int idx, int val)
{
	while(idx <= M)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int get(int *tree, int idx)
{
	int ans = 0;
	while(idx > 0)
	{
		ans += tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

main()
{
	int N, Q;
	scanf("%d", &N);
	scanf("%d", &Q);

	int *row_val = new int[N];
	int *col_val = new int[N];
	int *row_time = new int[N];
	int *col_time = new int[N];

	int *row_one_count = new int[Q + 1];
	int *col_one_count = new int[Q + 1];
	int *row_zero_count = new int[Q + 1];
	int *col_zero_count = new int[Q + 1];

	int *row_zero = new int[1 + M];
	int *row_one = new int[1 + M];
	int *col_zero = new int[1 + M];
	int *col_one = new int[1 + M];

	memset(row_val, 0, N * sizeof(int));
	memset(col_val, 0, N * sizeof(int));
	memset(row_time, 0, N * sizeof(int));
	memset(col_time, 0, N * sizeof(int));

	memset(row_zero_count, 0, (Q + 1) * sizeof(int));
	memset(col_zero_count, 0, (Q + 1) * sizeof(int));
	memset(row_one_count, 0, (Q + 1) * sizeof(int));
	memset(col_one_count, 0, (Q + 1) * sizeof(int));

	memset(row_zero, 0, (1 + M) * sizeof(int));
	memset(row_one, 0, (1 + M) * sizeof(int));
	memset(col_zero, 0, (1 + M) * sizeof(int));
	memset(col_one, 0, (1 + M) * sizeof(int));

	char *buf = new char[20];
	for (int i = 1; i <= Q; i++)
	{
		scanf("%s", buf);
		if (buf[3] == 'Q')
		{
			int x;
			scanf("%d", &x);
			x--;

			if (buf[0] == 'R')
			{
				int t = row_time[x];
				if (row_val[x] == 0)
				{
					int s = col_one_count[i - 1] - col_one_count[t];
					s -= get(col_zero, M - t);
					printf("%d\n", N - s);
				}
				else
				{
					int s = col_zero_count[i - 1] - col_zero_count[t];
					s -= get(col_one, M - t);
					printf("%d\n", s);
				}
			}
			else
			{
				int t = col_time[x];
				if (col_val[x] == 0)
				{
					int s = row_one_count[i - 1] - row_one_count[t];
					s -= get(row_zero, M - t);
					printf("%d\n", N - s);
				}
				else
				{
					int s = row_zero_count[i - 1] - row_zero_count[t];
					s -= get(row_one, M - t);
					printf("%d\n", s);
				}
			}

			row_zero_count[i] = row_zero_count[i - 1];
			col_zero_count[i] = col_zero_count[i - 1];
			row_one_count[i] = row_one_count[i - 1];
			col_one_count[i] = col_one_count[i - 1];
		}
		else
		{
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			x--;

			if (buf[0] == 'R')
			{
				if (y == 1)
				{
					row_one_count[i] = row_one_count[i - 1] + 1;
					row_zero_count[i] = row_zero_count[i - 1];
				}
				else
				{
					row_zero_count[i] = row_zero_count[i - 1] + 1;
					row_one_count[i] = row_one_count[i - 1];
				}

				col_zero_count[i] = col_zero_count[i - 1];
				col_one_count[i] = col_one_count[i - 1];

				if (row_time[x] > 0)
				{
					if (row_val[x] != y)
					{
						if (y == 0)
					 		update(row_zero, M - row_time[x], 1);
						else	
							update(row_one, M - row_time[x], 1);
					}
					else
					{
						if (y == 1)
					 		update(row_zero, M - row_time[x], 1);
						else	
							update(row_one, M - row_time[x], 1);
					}
				}

				row_val[x] = y;
				row_time[x] = i;
			}
			else
			{
				if (y == 1)
				{
					col_one_count[i] = col_one_count[i - 1] + 1;
					col_zero_count[i] = col_zero_count[i - 1];
				}
				else
				{
					col_zero_count[i] = col_zero_count[i - 1] + 1;
					col_one_count[i] = col_one_count[i - 1];
				}

				row_zero_count[i] = row_zero_count[i - 1];
				row_one_count[i] = row_one_count[i - 1];
				
				if (col_time[x] > 0)
				{
					if (col_val[x] != y)
					{
						if (y == 0)
							update(col_zero, M - col_time[x], 1);
						else
							update(col_one, M - col_time[x], 1);
					}
					else
					{
						if (y == 1)
							update(col_zero, M - col_time[x], 1);
						else
							update(col_one, M - col_time[x], 1);
					}
				}

				col_val[x] = y;
				col_time[x] = i;
			}
		}
		//std::cout << i << " : " << row_zero_count[i] << " " << row_one_count[i] << "  " << col_zero_count[i] << "  " << col_one_count[i] << std::endl;
	}

	delete[] row_val;
	delete[] col_val;
	delete[] row_time;
	delete[] col_time;
	delete[] row_zero_count;
	delete[] col_zero_count;
	delete[] row_one_count;
	delete[] col_one_count;
	delete[] row_zero;
	delete[] row_one;
	delete[] col_zero;
	delete[] col_one;
}

