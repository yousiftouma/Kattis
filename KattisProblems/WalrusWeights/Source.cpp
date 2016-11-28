#include <bits/stdc++.h>
using namespace std;

bool available[2005];
int main()
{
	int n; cin >> n; int weight;
	vector<int> weights;
	memset(available, false, sizeof(available));
	available[0] = true;
	while (n--)
	{
		cin >> weight;
		weights.push_back(weight);
	}
	for (auto w : weights)
	{
		for (int i = 2003-w; i >=0; i--)
		{
			if (available[i])
			{
				available[i + w] = true;
			}
		}
	}

	for (int i = 0; i<=1000; i++)
	{
		if (available[1000 + i]) {
			cout << 1000 + i << endl;
			return 0;
		}
		if (available[1000 - i]) {
			cout << 1000 - i << endl;
			return 0;
		}
	}
	return 0;

}