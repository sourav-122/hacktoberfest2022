// CPP program to split array and move first
// part to end.
#include <bits/stdc++.h>
using namespace std;

// Function to split array and
// move first part to end
void splitArr(int arr[], int length, int rotation)
{
	int tmp[length * 2] = {0};

	for(int i = 0; i < length; i++)
	{
		tmp[i] = arr[i];
		tmp[i + length] = arr[i];
	}

	for(int i = rotation; i < rotation + length; i++)
	{
		arr[i - rotation] = tmp[i];
	}
}

// Driver code
int main()
{
	int arr[] = { 12, 10, 5, 6, 52, 36 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int position = 2;

	splitArr(arr, n, position);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	return 0;
}
/*
Output
5 6 52 36 12 10 
Time complexity: O(n)
Space complexity: O(2*n)
*/
