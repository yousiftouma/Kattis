#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
struct Node {
	int startNeighbors = 0;
	set<Node*> neighbors;
	int name;
};
int main()
{
	Node* dummyNode = new Node();
	vector<Node*> nodes;
	nodes.push_back(dummyNode);
	int C, P, X, L;
	cin >> C >> P >> X >> L;
	for (int i = 1; i <= C; i++) {
		Node* node = new Node();
		node->name = i;
		nodes.push_back(node);
	}
	while (P--) {
		int a, b;
		cin >> a >> b;
		nodes[a]->neighbors.insert(nodes[b]);
		nodes[a]->startNeighbors++;
		nodes[b]->neighbors.insert(nodes[a]);
		nodes[b]->startNeighbors++;
	}
	queue<Node*> bfsQ;
	set<Node*> bfsSet;
	bfsQ.push(nodes[L]);
	bfsSet.insert(nodes[L]);
	Node* curr;
	while (!bfsQ.empty()) {
		curr = bfsQ.front();bfsQ.pop();
		bfsSet.erase(bfsSet.find(curr));
		double currNeigh = ((double)curr->neighbors.size());
		double half = ((double)curr->startNeighbors) / 2.0;
		bool willLeave = half >= currNeigh;
		if (willLeave || nodes[L] == curr) {
			if (nodes[X] == curr)
			{
				cout << "leave";
				return 0;
			}
			for (auto it = curr->neighbors.begin(); it != curr->neighbors.end(); it++) {
				if (bfsSet.find(*it) == bfsSet.end())
				{
					bfsQ.push((Node*)*it);
					bfsSet.insert(*it);
				}
				auto me = ((Node*)*it)->neighbors.find(curr);
				((Node*)*it)->neighbors.erase(me);
				//((Node*)*it)->startNeighbors--;
			}
		}
	}
	cout << "stay";
	return 0;
}