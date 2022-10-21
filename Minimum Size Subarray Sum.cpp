// Problem Statement

// Given an array of positive 
// integers a and a positive integer target,
// we need to find minimum length subarray
// with sum greater than or equal to given target.

    int minsubarrylength(int target,vector<int>&a) {
        
        // target - given target value
        // n -size of array
        // start- starting point of the window

        // ans- to calculate subarray sum
        // initially it is zero
        
        int n=a.size(),start=0,len=1e9,ans=0;
        
        // we will be using sliding window
        // to solve the problem in O(n) time

        for(int i=0;i<n;i++)
        {
            ans+=(a[i]);
            
            while(ans>target)
            {
                // compress the window
                ans-=a[start];
                len=min(len,i-start+1);
                start++;
            }
            if(ans>=target)
            {
                len=min(len,i-start+1);
            }
        }
        return len>=1e8?0:len;
    }

    // time complexity- O(size of array)
    // space complexity- O(1)
