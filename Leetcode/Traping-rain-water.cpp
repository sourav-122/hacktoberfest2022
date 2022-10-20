class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2)
            return 0;
        int sum=0;
       int maxLeft=height[0];
        int maxRight=height[height.size()-1];
        int i=1,j=height.size()-2;
        while(i<=j)
        {
            if(maxLeft>maxRight)
            {
                if(height[j]>=maxRight)
                    maxRight=height[j];
                else
                sum=sum+(maxRight-height[j]);
                j--;
                
            }
            else
            {
                if(height[i]>=maxLeft)
                    maxLeft=height[i];
                else
                sum=sum+(maxLeft-height[i]);
                i++;
            }
                
        }
        return sum;
        
    }
};
