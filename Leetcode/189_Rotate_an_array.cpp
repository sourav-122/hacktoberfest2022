class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int len=nums.size();
        k%=len;
        if(k==0)
            return;
		// reversing first size-k element
        reverse(nums.begin(),nums.end()-k);
		
		// reversing last k element
        reverse(nums.end()-k,nums.end());
		
		//reversing the whole array
        reverse(nums.begin(),nums.end());
    }
};
