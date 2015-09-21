#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned int N;
	unsigned int M;

	while (true) {
		vector<unsigned int> jacks;
		unsigned int res = 0;
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		unsigned int cd;
		while (N > 0) {
			cin >> cd;
			jacks.push_back(cd);
			--N;
		}
		while (M > 0) {
			cin >> cd;
			if (binary_search(jacks.begin(), jacks.end(), cd)){
				++res;
			}
			--M;
		}
		cout << res << endl;
	}

	return 0;
}