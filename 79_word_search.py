class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row_len = len(board)
        column_len = len(board[0])
        word_len = len(word)

        def checker(letter_no, row, column):
            # end con
            if letter_no is word_len:
                return True
            # checking out of bounds, word not equal
            if (
                row < 0
                or row >= row_len
                or column < 0
                or column >= column_len
                or board[row][column] != word[letter_no]
            ):
                return False
            # replacing visited chars with empty string
            tmp = board[row][column]
            board[row][column] = ""
            # checking up, down, left, right
            if (
                checker(letter_no + 1, row + 1, column)
                or checker(letter_no + 1, row - 1, column)
                or checker(letter_no + 1, row, column - 1)
                or checker(letter_no + 1, row, column + 1)
            ):
                return True

            # replacing the empty string with the correct value
            board[row][column] = tmp
            return False

        # loop
        for i in range(row_len):
            for j in range(column_len):
                if checker(0, i, j):
                    return True
        return False
