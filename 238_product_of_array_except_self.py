from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero_ctr = 0
        v1 = 1
        v2 = 1
        for i in nums:
            if i == 0:
                zero_ctr +=1
                v1 *= i
                continue
            v1 *= i
            v2 *= i
        if zero_ctr > 1:
            return [0]*len(nums)
        elif zero_ctr == 1:
            for i in range(len(nums)):
                if nums[i] != 0:
                    nums[i] = v1 // nums[i]
                else:
                    nums[i] = v2
            return nums
        else:
            for i in range(len(nums)):
                nums[i] = v1 // nums[i]
            return nums
