class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            # using bit shifting to reduce time rather than divided by 2
            mid = left + ((right - left) >> 1)

            # To filter duplicate values
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            
            # mid is in the rotation part
            elif nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
                
        return nums[left]
