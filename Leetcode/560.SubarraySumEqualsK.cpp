#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int>mp;
        int psum=0;
        int count=0;
        mp[0]=1;
        
        for(int i=0;i<nums.size();i++){

            psum+=nums[i];
            
            if(mp[psum-k]>0){
                count+=mp[psum-k];
                
            }
            mp[psum]++;
        
        
        }
        return count;
        
    }
};