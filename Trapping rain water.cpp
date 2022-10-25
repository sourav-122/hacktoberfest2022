class Solution {
public:
    int trap(vector<int>& h) {
        // edge case: empty input
        if (!h.size()) return 0;
        // support variables
        int len = h.size(), dp[len], currMax = -1, res = 0;
        // computing the maximum capacity looking from left
        for (int i = 0, e; i < len; i++) {
            e = h[i];
            currMax = max(currMax, e);
            dp[i] = currMax - e;
        }
        // computing the maximum capacity looking from right
        currMax = -1;
        for (int i = len - 1, e; i > -1; i--) {
            e = h[i];
            currMax = max(currMax, e);
            res += min(dp[i], currMax - e);
        }
        return res;
    }
};
