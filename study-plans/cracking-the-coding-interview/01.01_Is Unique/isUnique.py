
# 2023-08-20
class Solution:
    def isUnique(self, astr: str) -> bool:
        if len(astr) > 26:
            return False
        s = set()
        for x in astr:
            if x in s:
                return False
            else:
                s.add(x)
        return True
