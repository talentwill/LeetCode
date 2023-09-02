class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def dfs(l, r, path):
            if len(path) == 2 * n:
                ans.append(path)
                return
            if r > l: # 剩余的右边括号多
                dfs(l, r - 1, path + ')')
            if l > 0:
                dfs(l - 1, r, path + '(')
        dfs(n, n, '')
        return ans
