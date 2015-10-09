#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	unsigned int persons, friendships, person1, person2;
	int value, sum;
	string ans = "POSSIBLE";
	while (cin >> persons >> friendships)
	{
		map<unsigned int, int> values;
		for (auto i = 0; i < persons; ++i)
		{
			cin >> value;
			values.insert(make_pair(i, value));
		}

		while (friendships > 0)
		{
			cin >> person1 >> person2;
			if(abs(values.at(person1)) > 0)
			{
				values.at(person2) += values.at(person1);
				values.at(person1) = 0;
			}
			--friendships;
		}
		for (auto f : values)
		{
			if (f.second != 0)
			{
				ans = "IMPOSSIBLE";
			}
		}	
		cout << ans << endl;
	}



	return 0;
}