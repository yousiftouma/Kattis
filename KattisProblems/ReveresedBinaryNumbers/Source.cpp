#include <bits/stdc++.h>
using namespace std;

int main ()
{

	long long n;
	cin >> n;
	long long num = n;
	vector<int> binary;
	bool first = false;
	for (int i = 30; i >= 0; --i)
	{
		if (num - pow(2,i) >= 0)
		{
			num -= pow(2, i);
			binary.push_back(1);
			first = true;
		}
		else
		{
			if (first)
			{
				binary.push_back(0);
			}
		}
	}
	reverse(binary.begin(), binary.end());
	long long ans = 0;
	for (int k = 0; k < binary.size() ;++k)
	{
		ans += binary[k] * pow(2, binary.size()-1-k);
	}
	cout << ans << endl;

	return 0;
}