// Given an integer array nums, return the most frequent even element.

// If there is a tie, return the smallest one. If there is no such element, return -1.

 

// Example 1:

// Input: nums = [0,1,2,2,4,4,1]
// Output: 2
// Explanation:
// The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
// We return the smallest one, which is 2.
// Example 2:

// Input: nums = [4,4,4,9,2,4]
// Output: 4
// Explanation: 4 is the even element appears the most.

class Solution {
public:
    int mostFrequentEven(vector<int>& A) {
        //For Runtime allocation in place of using array of size 10^5
        unordered_map<int,int> mp;
        int val=1e6,freq=0;
        for(auto i:A){
            //if even element
            if(i%2==0){
                //increase frequency in map
                mp[i]++;
                //Update smallest with greatest frequency
                if(mp[i]>freq or mp[i]==freq and i<val){
                    val=i;
                    freq=mp[i];
                }
            }
        }
        return freq==0? -1 : val;
    }
};
