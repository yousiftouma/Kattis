#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int frontSprockets;
	int backSprockets;
	int teeth;

	while (cin >> frontSprockets)
	{
		if (frontSprockets == 0) break;
		cin >> backSprockets;
		vector<int> frontTeeth;
		vector<double> ratios;
		while (frontSprockets > 0)
		{
			cin >> teeth;
			frontTeeth.push_back(teeth);
			--frontSprockets;
		}

		while (backSprockets > 0)
		{
			cin >> teeth;
			for (auto f : frontTeeth)
			{
				ratios.push_back(static_cast<double>(teeth) / static_cast<double>(f));
			}
			--backSprockets;
		}

		sort(ratios.begin(), ratios.end());

		auto res = 0.0;

		for (auto i = 0; i < ratios.size() - 1; ++i)
		{
			if ((ratios[i+1] / ratios[i]) > res)
			{
				res = ratios[i + 1] / ratios[i];
			}
		}

		cout << fixed << setprecision(2) << res << endl;
	}
	return 0;
}