#include <bits/stdc++.h>
using namespace std;

const int INF = 150000;
typedef pair<int, int> coin;

int T[302][302];

int main()
{
	int cases; cin >> cases;
	while (cases--)
	{
		vector<coin> coins;
		int m, s; cin >> m >> s;
		for (int i = 0; i <= s; i++)
		{
			for (int j = 0; j <= s; j++)
			{
				T[i][j] = INF;
			}
		}
		T[0][0] = 0;
		while (m--)
		{
			int conv, infotech; cin >> conv >> infotech;
			coin c = make_pair(conv, infotech);
			coins.push_back(c);
		}

		for (coin c : coins)
		{
			for (int i = c.first; i <= s; i++)
			{
				for (int j = c.second; j <= s; j++)
				{
					T[i][j] = min(T[i][j], 1 + T[i-c.first][j-c.second]);
				}
			}
		}
		int best = INF;
		for (int i = 0; i <= s; i++)
		{
			for (int j = 0; j <= s; j++)
			{
				if (sqrt(i*i + j*j) == s*1.0)
				{
					best = min(best, T[i][j]);
				}
			}
		}
		if (best < INF) cout << best << endl;
		else cout << "not possible" << endl;
	}
	return 0;
}