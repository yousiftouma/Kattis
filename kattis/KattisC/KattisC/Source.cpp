#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	int inputs;
	int queries;
	auto cases = 0;
	int size;
	long input;
	long query;
	long res;
	size_t i;
	size_t j;
	vector<long> numbers;
	vector<long> sums;
	while (cin >> inputs) {
		numbers.clear();
		sums.clear();
		++cases;
		cout << "Case " << cases << ":" << endl;
		for (size = inputs; size > 0; --size) {
			cin >> input;
			numbers.push_back(input);
		}
		for (i = 0; i < inputs - 1; ++i) {
			for (j = i + 1; j < inputs; ++j) {
				sums.push_back(numbers[i] + numbers[j]);
			}
		}
		cin >> queries;
		for (queries; queries > 0; --queries) {
			cin >> query;
			res = *sums.begin();
			for (auto f : sums) {
				if (abs(f - query) < abs(res - query)) {
					res = f;
				}
				//else if (res != f) break;
			}
			cout << "Closest sum to " << query << " is " << res << "." << endl;
		}
	}
	return 0;
}