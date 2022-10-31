# Problem link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        
        horizontalCuts.sort()
        verticalCuts.sort()

        maxH = h - horizontalCuts[-1]
        maxW = w - verticalCuts[-1]
        
        prev = 0
        for num in horizontalCuts:
            maxH = max(maxH, num - prev)
            prev = num
        
        prev = 0
        for num in verticalCuts:
            maxW = max(maxW, num - prev)
            prev = num
        
        return (maxH * maxW)%(10**9+7)
