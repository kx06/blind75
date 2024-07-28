class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if text1 in text2:
            return len(text1)
        if text2 in text1:
            return len(text2)
        len_t1 = len(text1)
        len_t2 = len(text2)
        dp = [[0] * (len_t2 + 1) for _ in range(len_t1 + 1)]
        for i in range(len_t1):
            for j in range(len_t2):
                if text1[i] == text2[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1])
        return dp[-1][-1]
