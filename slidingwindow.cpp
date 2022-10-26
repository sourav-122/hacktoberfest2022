/* Question:Given an array arr[] containing N positive integers and an integer K. The task is to replace every array element with the average of previous K and next K elements. 
Also, if K elements are not present then adjust use the maximum number of elements available before and after.


Approach: Consider that every element has K next and previous elements and take an window of size 2*K + 1 to cover this whole range.
Now initially find the sum of first (K+1) elements.
While traversing the array:
Calculate the average by dividing the sum with (size of window-1).
Add the next element after the rightmost end of the current window.
Remove the leftmost element of the current window. This will shift the window one position to right
Print the resultant array.*/


#include <bits/stdc++.h>
using namespace std;
 
// Function to replace all array elements
// with the average of previous and
// next K elements
void findAverage(int arr[], int N, int K)
{
    int i, sum = 0, next, prev, update;
    int cnt = 0;
 
    // Calculate initial sum of K+1 elements
    for (i = 0; i <= K and i < N; i++) {
        sum += arr[i];
        cnt += 1;
    }
 
    // Using the sliding window technique
    for (i = 0; i < N; i++) {
        update = sum - arr[i];
        cout << update / (cnt - 1) << " ";
        next = i + K + 1;
        prev = i - K;
        if (next < N) {
            sum += arr[next];
            cnt += 1;
        }
        if (prev >= 0) {
            sum -= arr[prev];
          cnt-=1;
        }
    }
}
 
// Driver Code
int main()
{
    int arr[] = { 9, 7, 3, 9, 1, 8, 11 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 2;
    findAverage(arr, N, K);
    return 0;
}
//output will be 5 7 6 4 7 7 4