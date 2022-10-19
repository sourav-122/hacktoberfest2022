/*
343. Integer Break

Input: n = 2
Output: 1
*/
class Solution {
public:
    int integerBreak(int n) {
        
        if (n <= 2)
            return 1;
        vector<int> maxArr(n+1, 0);
        maxArr[1] = 0;
        maxArr[2] = 1; // 2=1+1 so maxArr[2] = 1*1
        
        for (int i=3; i<=n; i++) {
            for (int j=1; j<i; j++) {
                maxArr[i] = max(maxArr[i], max(j*(i-j), j*maxArr[i-j]));
            }
        }
        return maxArr[n];
    }
};
