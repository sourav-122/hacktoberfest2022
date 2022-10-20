// You are given an integer array nums and an integer k.

// Find the longest subsequence of nums that meets the following requirements:

// The subsequence is strictly increasing and
// The difference between adjacent elements in the subsequence is at most k.
// Return the length of the longest subsequence that meets the requirements.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
// Output: 5
// Explanation:
// The longest subsequence that meets the requirements is [1,3,4,5,8].
// The subsequence has a length of 5, so we return 5.
// Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.
// Example 2:

// Input: nums = [7,4,5,1,8,12,4,7], k = 5
// Output: 4
// Explanation:
// The longest subsequence that meets the requirements is [4,5,8,12].
// The subsequence has a length of 4, so we return 4.

constexpr int N = 100001;
class Solution {
public: 
    array<int, 2*N> seg{};
    
    void update(int pos, int val){ // update max
        pos += N;
        seg[pos] = val;
 
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = max(seg[2*pos], seg[2*pos+1]);
        }
    }
 
    int query(int lo, int hi){ // query max [lo, hi)
        lo += N;
        hi += N;
        int res = 0;
 
        while (lo < hi) {
            if (lo & 1) {
                res = max(res, seg[lo++]);
            }
            if (hi & 1) {
                res = max(res, seg[--hi]);
            }
            lo >>= 1;
            hi >>= 1;
        }
        return res;
    }
    
    int lengthOfLIS(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < size(A); ++i){
            int l = max(0, A[i]-k);
            int r = A[i];
            int res = query(l, r) + 1; // best res for the current element
            ans = max(res, ans);
            update(A[i], res); // and update it here
        }
        
        return ans;
    }
};
