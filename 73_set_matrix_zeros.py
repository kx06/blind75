class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        row_len = len(matrix)
        if row_len is 0:
            return
        column_len = len(matrix[0])

        col1 = False
        row1 = False

        for x in range(column_len):
            if matrix[0][x] == 0:
                row1 = True

        for y in range(row_len):
            if matrix[y][0] == 0:
                col1 = True

        for y in range(1, row_len):
            for x in range(1, column_len):
                if matrix[y][x] == 0:
                    matrix[y][0] = matrix[0][x] = 0

        for y in range(1, row_len):
            for x in range(1, column_len):
                matrix[y][x] = (
                    0 if matrix[0][x] == 0 or matrix[y][0] == 0 else matrix[y][x]
                )

        if col1 == True:
            for y in range(row_len):
                matrix[y][0] = 0

        if row1 == True:
            for x in range(column_len):
                matrix[0][x] = 0
