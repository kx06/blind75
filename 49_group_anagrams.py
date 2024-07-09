from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        word_dict = defaultdict(list)
        for i in strs:
            sorted_word = "".join(sorted(i))
            word_dict[sorted_word].append(i)
        return list(word_dict.values())
