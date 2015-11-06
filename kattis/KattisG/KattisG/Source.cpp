#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	//freopen("output.txt", "w", stdout);
	int commands, op, operand;
	bool isQ, isS, isPq;
	while (cin >> commands)
	{
		queue<int> que;
		stack<int> stack;
		priority_queue<int> prioQue;
		isQ = true;
		isPq = true;
		isS = true;
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
					if (que.empty() || que.front() != operand) isQ = false;
					if(isQ) que.pop();
				}
				
				if(isS)
				{
					if (stack.empty() || stack.top() != operand) isS = false;
					if(isS) stack.pop();
				}
				
				if (isPq)
				{
					if (prioQue.empty() || prioQue.top() != operand) isPq = false;
					if(isPq) prioQue.pop();
				}	
			}
		}
		if (!isQ && !isS && !isPq) cout << "impossible\n";
		else if (isQ && !isS && !isPq) cout << "queue\n";
		else if (!isQ && isS && !isPq) cout << "stack\n";
		else if (!isQ && !isS && isPq) cout << "priority queue\n";
		else cout << "not sure\n";
	}

	return 0;
}