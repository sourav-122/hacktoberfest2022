# 3. Longest Substring Without Repeating Characters
# Given a string s, find the length of the longest substring without repeating characters.

class Solution(object):
    def lengthOfLongestSubstring(self, s:str) ->int:
        charSet = set()
        l=0
        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l+=1
            charSet.add(s[r])
            res = max(res,r-l+1)
        return res
        
        
# Input: s = "abcabcbb"
# Output: 3
# Complexity O(n^2)
