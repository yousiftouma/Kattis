#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> trees;
	while (N--) {
		int tree;
		cin >> tree;
		trees.push_back(tree);
	}
	sort(trees.begin(), trees.end());
	int maxDaysLeft = 0;
	int result = 0;
	for (int i = trees.size() - 1; i >= 0; i--) {
		result++;
		maxDaysLeft--;
		if (trees[i] > maxDaysLeft) {
			maxDaysLeft = trees[i];
		}
	}
	cout << result + maxDaysLeft + 1;



	return 0;
}