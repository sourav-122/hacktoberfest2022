 int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss; // set to check char that are already in window
        
		// ans is the returning variable
		// l and r are window sliders
		int l=0,ans=0;
        for(int r=0;r<s.size();++r)
        {
			// if char is present in window then keep removing 
			//  from the left size untill it is gone 
            while(ss.find(s[r])!=ss.end())
            {
                ss.erase(s[l]);
                l++;
            }
            
			 ss.insert(s[r]); // insert the new char in set
            ans = max(ans,r-l+1); // keep updating the max window size
        }
        return ans; 
    }
