/*Given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit achievable on completion of at most two transactions.

Note: No engagement in multiple transactions simultaneously (i.e., you must sell the stock before you buy again) is allowed.
*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));
    
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                 int profit=0;
        
                 if(buy){
                     profit=max(-prices[ind] + dp[ind+1][0][cap], 0+ dp[ind+1][1][cap]);
                 }
                 else{
                     profit=max(prices[ind]+ dp[ind+1][1][cap-1] , 0+ dp[ind+1][0][cap]);
                 }
                 dp[ind][buy][cap]=profit;
                }
                 
            }
        }  
        return dp[0][1][2];
    }
};

/*
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6

Input: prices = [1,2,3,4,5]
Output: 4
*/