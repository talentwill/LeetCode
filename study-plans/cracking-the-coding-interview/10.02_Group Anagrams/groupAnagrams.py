# 2023-09-08
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for word in strs:
            # 把单词排序后作为Key
            mp[''.join(sorted(word))].append(word)
        return list(mp.values())
