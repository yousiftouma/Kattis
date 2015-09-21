#include <iostream>
#include <set>
using namespace std;

int main() {
	int N;
	int M;
	set<int> jacks, jills;

	while (true) {
		int res = 0;
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		int cd;
		while (N > 0) {
			cin >> cd;
			jacks.insert(cd);
			--N;
		}
		while (M > 0) {
			cin >> cd;
			jills.insert(cd);
			--M;
		}

		for (int cd : jacks) {
			if (jills.find(cd) != jills.end())
				++res;
		}
		cout << res << endl;

	}

	return 0;
}