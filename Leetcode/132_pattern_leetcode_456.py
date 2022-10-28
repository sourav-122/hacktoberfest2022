def find132pattern(self, nums: List[int]) -> bool:
    currentMin = nums[0]
    s = []

    for m in nums[1:]:
        while s and m >= s[-1][0]:
            s.pop()
        if s and m > s[-1][1]:
            return True
        s.append([m,currentMin])
        currentMin = min(currentMin , m)
    return False

    