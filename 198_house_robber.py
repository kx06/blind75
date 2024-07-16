class Solution:
    def rob(self, nums: List[int]) -> int:
        nums = tuple(nums)
        ln = len(nums)
        if ln == 0:
            return True

        p1 = 0
        p2 = 0

        for i in nums:
            tmp = p1
            p1 = max(p2 + nums, p1)
            p2 = tmp
        return dp(nums, ln)
