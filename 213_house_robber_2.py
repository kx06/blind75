class Solution:
    def rob(self, nums: List[int]) -> int:
        ln = len(nums)
        if ln == 0:
            return True

        p1 = 0
        p2 = 0
        ln = len(nums)

        for i in nums[:ln]:
            tmp = p1
            p1 = max(p2 + i, p1)
            p2 = tmp
        m1 = p1
        p1 = 0
        p2 = 0
        for i in nums[2:]:
            tmp = p1
            p1 = max(p2 + i, p1)
            p2 = tmp
        return max(p1, m1)
