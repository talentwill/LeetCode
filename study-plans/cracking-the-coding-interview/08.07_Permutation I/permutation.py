class Solution:
    def permutation(self, s: str) -> List[str]:
        vis = [False] * len(s)
        ans = []

        def dfs(path):
            if len(path) == len(s):
                ans.append(path)
                return
            for i, c in enumerate(s):
                if not vis[i]:
                    vis[i] = True
                    dfs(path + c)
                    vis[i] = False
        dfs('')
        return ans
