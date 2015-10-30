#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	freopen("output.txt", "w", stdout);
	int commands, op, operand;
	int isQ, isS, isPq;
	while (cin >> commands)
	{
		queue<int> que;
		stack<int> stack;
		priority_queue<int> prioQue;
		isQ = 1;
		isPq = 1;
		isS = 1;
		while (commands--)
		{
			cin >> op >> operand;
			if (op == 1)
			{
				if (isQ) que.push(operand);
				if (isS) stack.push(operand);
				if (isPq) prioQue.push(operand);
			}
			else
			{
				if(isQ) {
					if (que.empty() || que.front() != operand) isQ = 0;
					else que.pop();
				}
				
				if(isS)
				{
					if (stack.empty() || stack.top() != operand) isS = 0;
					else stack.pop();
				}
				
				if (isPq)
				{
					if (prioQue.empty() || prioQue.top() != operand) isPq = 0;
					else prioQue.pop();
				}	
			}
		}
		auto sum = isQ + isS + isPq;
		if (sum > 1) cout << "not sure" << endl;
		else if (sum == 0) cout << "impossible" << endl;
		else if (isQ == 1) cout << "queue" << endl;
		else if (isS == 1) cout << "stack" << endl;
		else if (isPq == 1) cout << "priority queue" << endl;
	}

	return 0;
}