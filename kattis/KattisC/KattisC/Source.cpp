#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	int inputs;
	int queries;
	int cases = 0;
	int size;
	int sumsSize;
	long input;
	long query;
	long res;
	long sum;
	vector<long> numbers;
	set<long> sums;
	while (true) {
		numbers.clear();
		sums.clear();
		cin >> inputs;
		size = inputs;
		++cases;
		cout << "Case " << cases << ":" << endl;
		for (inputs; inputs > 0; --inputs) {
			cin >> input;
			numbers.push_back(input);
		}
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i + 1; j < size; ++j) {
				sums.insert(numbers[i] + numbers[j]);
			}
		}
		sumsSize = sums.size();
		cin >> queries;
		for (queries; queries > 0; --queries) {
			cin >> query;
			res = *sums.begin();
			for (auto f : sums) {
				cout << "currsum = " << f << endl;
				if (abs(f - query) < abs(res - query)) {
					res = f;
				}
				else if (!(res == f)) break;
			}
			cout << "Closest sum to " << query << " is " << res << "." << endl;
		}
	}

	return 0;
}