#include <iostream>
#include <array>
using namespace std;

void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration. 
	int * b = new int[high + 1 - low];
	int h, i, j, k;
	h = low;
	i = 0;
	j = mid + 1;
	// Merges the two array's into b[] until the first one is finished
	while ((h <= mid) && (j <= high))
	{
		if (a[h] <= a[j])
		{
			b[i] = a[h];
			h++;
		}
		else
		{
			b[i] = a[j];
			j++;
		}
		i++;
	}
	// Completes the array filling in it the missing values
	if (h>mid)
	{
		for (k = j;k <= high;k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	else
	{
		for (k = h;k <= mid;k++)
		{
			b[i] = a[k];
			i++;
		}
	}
	// Prints into the original array
	for (k = 0;k <= high - low;k++)
	{
		a[k + low] = b[k];
	}
	delete[] b;
}

void merge_sort(int a[], const int low, const int high)		// Recursive sort ...
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}


int binary_srch_ret_index(int inp[], int e, int low, int high) {

	if (low > high) {
		return -1;
	}

	int mid = (low + high) / 2;

	if (e == inp[mid]) {
		return mid;
	}

	if (e < inp[mid]) {
		return binary_srch_ret_index(inp, e, low, mid - 1);
	}
	else {
		return binary_srch_ret_index(inp, e, mid + 1, high);
	}
}




int main()
{
	auto students = new int[1000000];
	int numberOfStudents, temp;
	cin >> numberOfStudents;
	int inversions = 0;
	for (auto i = 0; i < numberOfStudents; ++i)
	{
		cin >> students[i];
	}

	auto unsorted = new int[1000000];
	for (auto i = 0; i < numberOfStudents; ++i)
	{
		unsorted[i] = students[i];
	}

	merge_sort(students, 0, numberOfStudents);
	
	for (auto i = 0; i < numberOfStudents; ++i)
	{
		auto index = binary_srch_ret_index(students, unsorted[i], 0, numberOfStudents - i - 1);
		inversions += index;
		for (auto k = index; k < numberOfStudents - i; ++k)
		{
			students[k] = students[k + 1];
		}
	}

	cout << inversions << endl;
	//delete students, unsorted;
	return 0;
}