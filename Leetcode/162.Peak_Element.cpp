//A peak element is an element that is strictly greater than its neighbors.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
int findPeakElement(vector<int>& nums) {
        int lmax = 0,ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[lmax]) lmax = i;
        }
        return max;
    }
 };
