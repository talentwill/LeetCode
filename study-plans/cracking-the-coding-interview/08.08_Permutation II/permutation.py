class Solution:
    def permutation(self, s: str) -> List[str]:
        n = len(s)
        vis = [False] * n
        ans = []
        s = sorted(s)

        def dfs(path):
            if len(path) == n:
                ans.append(path)
                return
            pre = None
            for i, c in enumerate(s):
                if pre != c and not vis[i]:
                    vis[i] = True
                    dfs(path + c)
                    vis[i] = False
                    pre = c  # 必须是要前一个选过的。
        dfs('')
        return ans
