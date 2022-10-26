/*
Question:Given a binary array a[] or size N and an integer K, the task is to find the longest subarray consisting of only 1s or only
 0s when at most K elements can be flipped (i.e change 1 to 0 or 0 to 1).


Approach:Finding the longest subarray containing only 1s with at most K -flips:
Declare variable cnt and an integer pointer left which will point at index 0 in the beginning.
Now run a loop from 0 to N and at any position: 
If arr[i] equals 0, then increase the cnt variable.
At any position, if the cnt is greater than K, move the left pointer to the right side and again check if arr[left] equals 0,  
Then decrease the cnt variable and run this loop until cnt is greater than K.
Store the maximum length of subarray containing only 1’s and calculate this length as (current index – left pointer + 1).
Find the longest subarray containing only 0s with at most K-flips and store its length in the similar way.
Return the maximum among both of the maximum lengths.
*/

// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the longest subarray
// following the given conditions
int longestSubSeg(int arr[], int N, int K)
{
    int cnt = 0;
    int left = 0;
    int maximum_len1 = 0;
    int maximum_len0 = 0;
 
    // Finding length of maximum subarray
    // containing 1's only with atmost k flips
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0)
            cnt++;
 
        while (cnt > K) {
            if (arr[left] == 0)
                cnt--;
            left++;
        }
        maximum_len1 = max(maximum_len1, i - left + 1);
    }
 
    // Set these variables to 0 for further use
    cnt = 0;
    left = 0;
 
    // Finding length of maximum subarray
    // containing 0's only with atmost k flips
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1)
            cnt++;
 
        while (cnt > K) {
            if (arr[left] == 1)
                cnt--;
            left++;
        }
        maximum_len0 = max(maximum_len0, i - left + 1);
    }
 
    return max(maximum_len1, maximum_len0);
}
 
// Driver code
int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 0, 1 };
    int K = 2;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << longestSubSeg(arr, N, K);
    return 0;
}
