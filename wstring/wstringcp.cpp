#include <iostream>
#include <string>
#include <vector>

using namespace::std;

main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string s;
		cin >> s;

		vector<vector<int> > P = vector<vector<int> >();
		int cnt = 0;
		int good = 0;

		vector<int> u(26, 0);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '#')
			{
				P.push_back(u);
				u = vector<int>(26, 0);
				if (cnt > 0)
					good++;

				cnt = 0;
			}
			else
			{
				u[s[i] - 'a']++;
				cnt++;
			}
		}
		if (cnt > 0)
			good++;

		P.push_back(u);

		if (good < 4)
			std::cout << "0" << std::endl;
		else
		{
			int n = P.size();
			vector<int> best(n, 0);
			vector<int> pref(n, 0);
			vector<int> suff(n, 0);

			vector<int> curr(26, 0);
			for (int i = 0; i < n; i++)
			{
				int m1 = 0;
				int m2 = 0;

				for (int j = 0; j < 26; j++)
				{
					if (P[i][j] > m1)
						m1 = P[i][j];

					curr[j] += P[i][j];
					if (curr[j] > m2)
						m2 = curr[j];
				}

				best[i] = m1;
				pref[i] = m2;
			}

			curr = vector<int>(26, 0);
			for (int i = n - 1; i >= 0; i--)
			{
				int m2 = 0;
				for (int j = 0; j < 26; j++)
				{
					curr[j] += P[i][j];
					if (curr[j] > m2)
						m2 = curr[j];
				}

				suff[i] = m2;
			}

			int ans = 0;
			for (int i = 1; i < (n - 2); i++)
			{
				if (pref[i - 1] > 0 && best[i] > 0 && best[i + 1] > 0 && suff[i + 2] > 0)
				{
					int x = pref[i - 1] + best[i] + best[i + 1] + suff[i + 2];
					if (x > ans)
						ans = x;
				}
			}

			if (ans > 0)
				std::cout << (ans + 3) << std::endl;
			else
				std::cout << "0" << std::endl;
		}
	}
}
