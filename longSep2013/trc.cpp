#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <utility>
#include <math.h>
#include <assert.h>
#include <algorithm>

using namespace::std;

#define EPS 1e-9

struct point
{
	long double x;
	long double y;
};

struct my_set
{
	int num_pts;
	long double Sx;
	long double Sx2;
	long double Sy;
	long double Sy2;
	long double Sxy;

	my_set()
	{
		num_pts = 0;
		Sx = 0;
		Sx2 = 0;
		Sy = 0;
		Sy2 = 0;
		Sxy = 0;
	}	

	void remove_point(point &pt)
	{
		num_pts--;
		Sx -= pt.x;
		Sx2 -= pt.x * pt.x;
		Sy -= pt.y;
		Sy2 -= pt.y * pt.y;
		Sxy -= pt.x * pt.y;
	}	

	void add_point(point &pt)
	{
		num_pts++;
		Sx += pt.x;
		Sx2 += pt.x * pt.x;
		Sy += pt.y;
		Sy2 += pt.y * pt.y;
		Sxy += pt.x * pt.y;
	}

	long double get_sum()
	{
		if (num_pts == 0)
			return 0;

		long double n = (long double) num_pts;
		long double Ex = Sx / n;
		long double Ex2 = Sx2 / n;
		long double Ey = Sy / n;
		long double Ey2 = Sy2 / n;
		long double Exy = Sxy / n;

		long double Vx = Ex2 - Ex * Ex;
		long double Vy = Ey2 - Ey * Ey;
		long double Cxy = Ex * Ey - Exy;
	
		// Consider axis-parallel lines.
		long double ans = n * min(Vx, Vy);

		if (Cxy >= -EPS && Cxy <= EPS)
		{
			return ans;
		}

		long double B = 0.5 * (Vy - Vx) / Cxy;
		long double b = -B + sqrtl(1 + B * B);

		long double t = (n * (Vy + b * b * Vx + 2.0 * b * Cxy)) / (1.0 + b * b);
		if (t < ans)
			ans = t;

		b = -B - sqrtl(1 + B * B);
		t = (n * (Vy + b * b * Vx + 2.0 * b * Cxy)) / (1.0 + b * b);
		if (t < ans)
			ans = t;
		
		return ans;
	}
};

long double comb(my_set &A, my_set &B, point &p1, point &p2)
{
	long double ans = -10;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0)
				A.add_point(p1);
			else
				B.add_point(p1);

			if (j == 0)
				A.add_point(p2);
			else
				B.add_point(p2);

			long double t = A.get_sum() + B.get_sum();
			if (ans < 0 || ans > t)
				ans = t;

			if (i == 0)
				A.remove_point(p1);
			else
				B.remove_point(p1);

			if (j == 0)
				A.remove_point(p2);
			else
				B.remove_point(p2);	
		}
	}

	return ans;
}

bool is_same(long double x, long double y)
{
	if (x > (y + EPS))
		return false;

	if (y > (x + EPS))
		return false;

	return true;
}

bool is_same(point &p1, point &p2)
{
	return (is_same(p1.x, p2.x) && is_same(p1.y, p2.y));
}

long double parallel_lines(vector<point> &pts, point &pt1, point &pt2)
{
	long double dx = pt2.x - pt1.x;
	long double dy = pt2.y - pt1.y;

	my_set above;
	my_set below;

	for (int i = 0; i < pts.size(); i++)
	{
		if (is_same(pts[i], pt1))
			continue;
		
		if (is_same(pts[i], pt2))
			continue;
		
		long double dx1 = pts[i].x - pt1.x;
		long double dy1 = pts[i].y - pt1.y;

		long double d = (dx * dy1 - dy * dx1);
		if ((d + EPS) >= 0)
			above.add_point(pts[i]);
		else
			below.add_point(pts[i]);
	}

	return comb(above, below, pt1, pt2);	
}

long double parallel_lines(vector<point> &pts)
{
	long double ans = -10;
	for (int i = 0; i < pts.size(); i++)
	{
		for (int j = i + 1; j < pts.size(); j++)
		{
			long double t = parallel_lines(pts, pts[i], pts[j]);
			if (ans < 0 || ans > t)
				ans = t;
		}
	}

	return ans;
}

long double vertical_lines(vector<point> &pts, point &pt1, point &pt2)
{
	long double dx = pt2.x - pt1.x;
	long double dy = pt2.y - pt1.y;
	long double dr = dx * dx + dy * dy;

	vector<int> sgn(pts.size(), 0);
	for (int i = 0; i < pts.size(); i++)
	{
		if (is_same(pts[i], pt1))
		{
			sgn[i] = 0;
			continue;
		}

		if (is_same(pts[i], pt2))
		{
			sgn[i] = 0;
			continue;
		}

		long double dx1 = pts[i].x - pt1.x;
		long double dy1 = pts[i].y - pt1.y;
	
		long double cross = dx * dy1 - dx1 * dy;
		if (cross > 0)
			sgn[i] = 1;
		else
			sgn[i] = -1;	
	}

	vector<pair<long double, int> > info;
	for (int i = 0; i < pts.size(); i++)
	{
		if (is_same(pts[i], pt1))
			continue;

		if (is_same(pts[i], pt2))
			continue;

		long double dx1 = pts[i].x - pt1.x;
		long double dy1 = pts[i].y - pt1.y;

		long double t = (dx * dx1 + dy * dy1) / dr;
		info.push_back(make_pair(t, i));
	}

	std::sort(info.begin(), info.end());

	my_set odd;
	my_set even;

	for (int i = 0; i < pts.size(); i++)
	{
		if (sgn[i] == 1)	
			odd.add_point(pts[i]);

		if (sgn[i] == -1)
			even.add_point(pts[i]);	
	}

	long double ans = comb(odd, even, pt1, pt2);
	
	for (int i = 0; i < info.size(); i++)
	{
		if (i < (info.size() - 1))
		{
			if (is_same(info[i].first, info[i + 1].first))
			{
				int index1 = info[i + 1].second;
				if (sgn[index1] == 1)
				{
					even.add_point(pts[index1]);
					odd.remove_point(pts[index1]);

					long double s = comb(odd, even, pt1, pt2);
					if (s < ans)
						ans = s;
					
					odd.add_point(pts[index1]);
					even.remove_point(pts[index1]);
				}
				else
				{
					odd.add_point(pts[index1]);
					even.remove_point(pts[index1]);
					
					long double s = comb(odd, even, pt1, pt2);
					if (s < ans)
						ans = s;
					
					even.add_point(pts[index1]);
					odd.remove_point(pts[index1]);
				}
			}
		}

		int index = info[i].second;
		if (sgn[index] == 1)
		{
			even.add_point(pts[index]);
			odd.remove_point(pts[index]);
		}
		else
		{
			odd.add_point(pts[index]);
			even.remove_point(pts[index]);
		}

		long double t = comb(odd, even, pt1, pt2);
		if (t < ans)
			ans = t;
	}

	return ans;
}

long double vertical_lines(vector<point> &pts)
{
	long double ans = -10;
	for (int i = 0; i < pts.size(); i++)
	{
		for (int j = i + 1; j < pts.size(); j++)
		{
			long double t = vertical_lines(pts, pts[i], pts[j]);
			if (ans < 0 || ans > t)
				ans = t;
		}
	}

	return ans;
}

main()
{
	int N;
	scanf("%d", &N);

	vector<point> pts(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%Lf", &pts[i].x);
		scanf("%Lf", &pts[i].y);
	}

	long double ans = min(vertical_lines(pts), parallel_lines(pts));
	ans /= (long double) N;

	printf("%.7f\n", (double) ans);
}
