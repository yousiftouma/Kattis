#include <iostream>
using namespace std;

int main()
{
	auto students = new int[1000000];
	int numberOfStudents, temp;
	cin >> numberOfStudents;
	cin >> students[0];
	auto swaps = 0;

	for (auto i = 1; i < numberOfStudents; ++i)
	{
		cin >> students[i];
/*		for (auto k = i - 1; k >= 0; --k)
		{
			if (students[k] > students[i])
			{
				temp = students[k];
				students[k] = students[i];
				students[i] = temp;
				++swaps;
			}
		}*/
	}

	auto gap = numberOfStudents;
	auto shrink = 1.3;
	bool swapped = true;
	while (gap != 1 || swapped == true)
	{
		gap = gap / shrink;
		if (gap < 1) gap = 1;
		int i = 0;
		swapped = false;
		while (i + gap < numberOfStudents)
		{
			if (students[i] > students[i + gap])
			{
				temp = students[i];
				students[i] = students[i + gap];
				students[i + gap] = temp;
				swapped = true;
				swaps += 1;
				
			}
			++i;
		}
	}

	
	cout << swaps << endl;
	delete students;
	return 0;
}