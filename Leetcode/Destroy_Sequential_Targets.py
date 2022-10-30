class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        nums.sort()
        dp = {}
        count = {}
        for i in nums:
            if i%space not in count:
                count[i%space]=0
            count[i%space]+=1
        
        ans = nums[0]
        maxx = 0
        for i in nums:
            if count[i%space]>maxx:
                maxx = count[i%space]
                ans = i
        return ans
