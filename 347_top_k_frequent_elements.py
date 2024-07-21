import heapq
from collections import Counter


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ctr = Counter(nums)
        maxHeap = [[-freq, num] for num, freq in ctr.items()]
        heapq.heapify(maxHeap)
        res = []
        for i in range(k):
            _, num = heapq.heappop(maxHeap)
            res.append(num)
        return res
