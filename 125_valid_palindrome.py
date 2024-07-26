class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_s = s.lower()
        first = 0
        last = len(new_s) - 1
        while True:
            while True:
                if not new_s[first].isalnum() and first < last:
                    first += 1
                else:
                    break
            while True:
                if not new_s[last].isalnum() and last > first:
                    last -= 1
                else: 
                    break
            if first >= last:
                return True
            if new_s[first] != new_s[last]:
                return False
            first += 1
            last -= 1
