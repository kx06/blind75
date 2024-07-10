class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        interval_len = len(intervals)
        if interval_len == 1 or interval_len == 0:
            return 0
        intervals = sorted(intervals, key=lambda elem: elem[1])
        end, output = intervals[0][1], 0
        for i in range(1, interval_len):
            if intervals[i][0] >= end:
                end = intervals[i][1]

            else:
                output += 1
        return output
