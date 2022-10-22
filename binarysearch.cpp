#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;                // Least element
        int high = nums.size() - 1; // Highest element

        // Loop while low and high intersect
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // Mid value to check target is left side of mid or right side of mid

            if (nums[mid] < target)
            {
                // If target > nums[mid] value
                // ==> target is on right side so we should search in the range (mid+1 to high) so change low to mid + 1;
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                // If target < nums[mid] value
                // ==> target is on left side so we should search in the range (low to mid-1) so change high to mid - 1;
                high = mid - 1;
            }
            else
            {
                // Found the target !!!
                return mid;
            }
        }
        // Target is not present in array
        return -1;
    }
};