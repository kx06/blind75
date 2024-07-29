from typing import List
from bisect import bisect_left


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res_list = []
        for i in nums:
            if len(res_list) == 0 or res_list[-1] < i:
                res_list.append(i)
            else:
                num = bisect_left(res_list, i)
                res_list[num] = i
        return len(res_list)
