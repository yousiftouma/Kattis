#include <iostream>
#include <queue>
#include <string>
using namespace std;

void makeQueues(queue<int>& leftQue, queue<int>& rightQue, int& carsWaiting) {
	int size;
	string side;
	while (carsWaiting > 0) {
		cin >> size >> side;
		if (side == "left") {
			leftQue.push(size);
		}
		else {
			rightQue.push(size);
		}
		--carsWaiting;
	}
}

int calcRes(queue<int>& leftQue, queue<int>& rightQue, int& res, int& ferrySize) {
	int side = 0;
	int currSize = ferrySize;
	while (true) {
		if (leftQue.empty() && rightQue.empty()) {
			if (currSize != ferrySize) {
				++res;
			}
			return res;
		}
		if (side == 0) {
			if (!leftQue.empty() && leftQue.front() <= currSize) {
				currSize -= leftQue.front();
				leftQue.pop();
			}
			else {
				currSize = ferrySize;
				side = abs(side - 1);
				++res;
			}
		}
		else {
			if (!rightQue.empty() && rightQue.front() <= currSize) {
				currSize -= rightQue.front();
				rightQue.pop();
			}
			else {
				currSize = ferrySize;
				side = abs(side - 1);
				++res;
			}
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	int ferrySize;
	int carsWaiting;
	queue<int> leftQue;
	queue<int> rightQue;
	while (cases > 0) {
		int res = 0;
		int currSide = 0;
		cin >> ferrySize >> carsWaiting;
		ferrySize *= 100;

		makeQueues(leftQue, rightQue, carsWaiting);

		res = calcRes(leftQue, rightQue, res, ferrySize);

		cout << res << endl;
		--cases;
	}
	return 0;
}
