// PROBLEM
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

// SOLUTION
class Solution
{
public:
    int maxCoins(vector<int> &num)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int g = 0; g < n; g++)
            for (int i = 0, j = g; j < n; i++, j++)
            {
                int maxm = 0;
                for (int k = i; k <= j; k++)
                {
                    int left = i == k ? 0 : dp[i][k - 1];
                    int right = j == k ? 0 : dp[k + 1][j];
                    int val = (i == 0 ? 1 : num[i - 1]) * num[k] * (j == n - 1 ? 1 : num[j + 1]);
                    maxm = max(maxm, left + val + right);
                }
                dp[i][j] = maxm;
            }
        return dp[0][n - 1];
    }
};