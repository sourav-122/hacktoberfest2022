class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       for(int i=0; i<n; i++){
          sum +=nums[i];
      }
      int leSum=0;
      int riSum=sum;
      for(int i=0; i<n; i++){
        riSum-=nums[i];
         if(riSum==leSum){
            return i;
          }
          leSum +=nums[i];
        }
        return -1;
        
    }
};
