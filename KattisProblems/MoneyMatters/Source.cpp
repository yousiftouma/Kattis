#include <bits/stdc++.h>
using namespace std;

struct Node
{
	long long value;
	vector<Node*> friends;
	bool visited = false;

	explicit Node(int val)
	{
		value = val;
	}
};

int main ()
{
	long long n, m, val, fr1, fr2;
	cin >> n >> m;
	vector<Node*> nodes;
	set<Node*> maNodes;
	while (n--)
	{
		cin >> val;
		auto newNode = new Node(val);
		nodes.push_back(newNode);
		maNodes.insert(newNode);
	}
	while (m--)
	{
		cin >> fr1 >> fr2;
		nodes[fr1]->friends.push_back(nodes[fr2]);
		nodes[fr2]->friends.push_back(nodes[fr1]);
	}
	Node* curr;
	while (!maNodes.empty())
	{
		auto it = maNodes.begin();
		curr = *it;
		queue<Node*> bfs;
		bfs.push(curr);
		long long sum = 0;
		while (!bfs.empty())
		{
			curr = bfs.front(); bfs.pop();
			if (curr->visited) continue;
			curr->visited = true;
			sum += curr->value;
			for (auto pal : curr-> friends)
			{
				if (!pal->visited) bfs.push(pal);
			}
		}
		if (sum != 0)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		maNodes.erase(it);
	}
	cout << "POSSIBLE" << endl;

	return 0;
}