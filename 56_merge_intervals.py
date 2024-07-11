class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        final_intervals = []
        start = intervals[0][0]
        end = intervals[0][1]
        for s, e in intervals[1:]:
            if end >= s and e > end:
                end = e
            else:
                final_intervals.append([start, end])
                start = s
                end = e
        final_intervals.append([start, end])
        return final_intervals
