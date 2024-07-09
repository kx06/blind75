class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix_length = len(matrix)
        for i in range(0, int(matrix_length / 2)):
            matrix[i], matrix[matrix_length - i - 1] = (
                matrix[matrix_length - i - 1],
                matrix[i],
            )
        for i in range(matrix_length):
            for k in range(i + 1):
                matrix[i][k], matrix[k][i] = matrix[k][i], matrix[i][k]
