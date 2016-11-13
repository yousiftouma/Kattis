#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main ()
{
	vector<pair<long long, long long> > customers;
	long long result = 0;
	list<long long> customersToProcess;
	long long N, T;
	cin >> N >> T;
	while (N--)
	{
		long long money, time;
		cin >> money >> time;
		auto customer = make_pair(money, time);
		customers.push_back(customer);
	}
	for (long long i = T - 1; i >= 0; i--)
	{
		for (auto cust : customers)
		{
			if (cust.second == i)
			{
				customersToProcess.push_back(cust.first);
			}
		}
		if (customersToProcess.size() > 0)
		{
			long long max = 0;
			for (auto money : customersToProcess)
			{
				if (money > max) max = money;
			}
			customersToProcess.remove(max);
			result += max;
		}
	}
	cout << result;

	return 0;
}