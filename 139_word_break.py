def wordBreak(s, wordDict):
    str_len = len(s)
    dp_array = [False] * (str_len + 1)
    dp_array[str_len] = True
    for i in range(str_len - 1, -1, -1):
        for word in wordDict:
            word_len = len(word)
            if (word_len + i) <= str_len and s[i : i + word_len] == word:
                dp_array[i] = dp_array[i + word_len]

            if dp_array[i]:
                break
    return dp_array[0]


s = "leetcode"
wordDict = ["leet", "code"]
res = wordBreak(s, wordDict)
print(res)
