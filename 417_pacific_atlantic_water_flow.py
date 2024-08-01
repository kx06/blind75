class Solution:
    def pacificAtlantic(self, heights):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        row_len = len(heights)
        col_len = len(heights[0])
        po = set()
        ao = set()

        def dfs(row, col, visited, prevHeight):
            if (
                (row, col) in visited
                or row < 0
                or col < 0
                or row == row_len
                or col == col_len
                or heights[row][col] < prevHeight
            ):
                return
            visited.add((row, col))
            dfs(row + 1, col, visited, heights[row][col])
            dfs(row, col + 1, visited, heights[row][col])
            dfs(row - 1, col, visited, heights[row][col])
            dfs(row, col - 1, visited, heights[row][col])

        for col in range(col_len):
            dfs(0, col, po, heights[0][col])
            dfs(row_len - 1, col, ao, heights[row_len - 1][col])
        for row in range(row_len):
            dfs(row, 0, po, heights[row][0])
            dfs(row, col_len - 1, ao, heights[row][col_len - 1])

        return list(po.intersection(ao))


it = iter(stdin)
output = open("user.out", "w")
for array in it:
    output.write(
        dumps(Solution.pacificAtlantic(Self, loads(array))).replace(" ", "") + "\n"
    )
exit()
