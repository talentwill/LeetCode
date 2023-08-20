class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        counts = defaultdict(int)
        for c in s:
            counts[c] += 1

        odd = 0
        for v in counts.values():
            if v % 2 == 1:
                odd += 1
            if odd > 1:
                return False
        return True