#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
	unordered_map<string, string> dict;
	string line;
	string val, key;
	while (getline(cin, line) && !line.empty()) {
		stringstream ss(line);
		ss >> val >> key;
		dict.insert(make_pair(key, val));
	}
	string lookup;
	while (cin >> lookup)
	{
		if (dict.find(lookup) != dict.end())
		{
			cout << dict[lookup] << endl;
		}
		else cout << "eh" << endl;
	}

	return 0;
}
