from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hash_set = set(nums)
        seq = 0
        while hash_set:
            num = hash_set.pop()
            prev_num = num - 1
            while prev_num in hash_set:
                hash_set.remove(prev_num)
                prev_num -= 1
            half = num + 1
            while half in hash_set:
                hash_set.remove(half)
                half += 1
            seq = max(seq, half - prev_num - 1)
        return seq
