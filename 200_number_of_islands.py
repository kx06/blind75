from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        ctr = 0
        visited = set()

        def dfs(row, col, grid, visited):
            if (
                row < 0
                or row >= rows
                or col < 0
                or col >= cols
                or grid[row][col] != "1"
                or (row, col) in visited
            ):
                return
            visited.add((row, col))
            dfs(row + 1, col, grid, visited)
            dfs(row - 1, col, grid, visited)
            dfs(row, col + 1, grid, visited)
            dfs(row, col - 1, grid, visited)

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    ctr += 1
                    dfs(r, c, grid, visited)

        return ctr


it = iter(stdin)
output = open("user.out", "w")
for array in it:
    output.write(dumps(Solution.numIslands(Self, loads(array))).replace(" ", "") + "\n")
exit()
