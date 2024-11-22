// C++ program for Implementing prefix sum array
#include <bits/stdc++.h>
using namespace std;
// you will learn concept of Prefix sum via this code
// Fills prefix sum array
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
	prefixSum[0] = arr[0];
	// Adding present element with previous element
	for (int i = 1; i < n; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];
}

// Driver Code
int main()
{
	int arr[] = { 10, 4, 16, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int prefixSum[n];

	// Function call
	fillPrefixSum(arr, n, prefixSum);
	for (int i = 0; i < n; i++)
		cout << prefixSum[i] << " ";
}
