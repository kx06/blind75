class Solution:

    def combinationSum(self, candidates, target):
        global_res_array = []

        def backtrack(index, arr, sum):
            if sum == target:
                global_res_array.append(list(arr))
                return
            if index >= len(candidates) or sum > target:
                return

            arr.append(candidates[index])
            backtrack(index, arr, sum + candidates[index])
            arr.pop()
            backtrack(index + 1, arr, sum)

        backtrack(0, [], 0)
        return global_res_array
