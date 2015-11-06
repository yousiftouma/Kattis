#include <iostream>
#include <vector>
using namespace std;

vector<int> students;
vector<int> extra; //used for merging
long long inversions; 

void merge(int start, int end, int mid)
{
	auto i = start, k = start, j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (students[i] < students[j])
		{
			extra[k] = students[i];
			k++;
			i++;
		} else
		{
			extra[k] = students[j];
			k++;
			j++;
			// number of inversions added is number of elements in left
			// subarray from i to end where i is current item checked in left subarray
			inversions += static_cast<long long>(mid) - 
				static_cast<long long>(i) + 
				static_cast<long long>(1);
		}
		
	}
	// merge rest of left
	while (i <= mid)
	{
		extra[k] = students[i];
		k++;
		i++;
	}
	// or
	// merge rest of right
	while (j <= end)
	{
		extra[k] = students[j];
		k++;
		j++;
	}

	// copy back result to original vector
	for (i = start; i < k; i++)
	{
		students[i] = extra[i];
	}
}

void mergeSort(int start, int end)
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, end, mid);
	}
}

int main()
{
	inversions = 0;
	int numberOfStudents;
	cin >> numberOfStudents;
	
	students.resize(numberOfStudents);
	extra.resize(numberOfStudents);

	for (auto i = 0; i < numberOfStudents; ++i)
	{
		cin >> students[i];
	}
	

	mergeSort(0, numberOfStudents - 1);
	
	cout << inversions << endl;
	return 0;
}