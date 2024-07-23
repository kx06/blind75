from collections import defaultdict


class Solution:
    def countBits(self, n: int) -> List[int]:
        table = defaultdict(int)
        res = [0, 1]
        table[0] = 0
        table[1] = 1
        ctr = 1
        flag = 1
        for i in range(2, n + 1, 2):
            table[i] = ctr
            table[i + 1] = ctr + 1
            flag += 1
            ctr = table[flag]
            res.append(table[i])
            res.append(table[i + 1])
        return res[: n + 1] if n % 2 == 0 else res
