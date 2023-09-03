class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:

        def conflict(sr, sc, visited):
            for r, c in enumerate(visited):
                # 判断相同列
                if c == sc:
                    return True
                # 判断对角线
                if abs(sr - r) == abs(sc - c):
                    return True
            return False

        ans = []

        def trans(visited):
            res = []
            for i in visited:
                s = ['.'] * n
                s[i] = 'Q'
                res.append(''.join(s))
            return res

        def dfs(row, visited):
            """
            # visited 表示已经摆的皇后的位置
            # visited[1,3,2,0], 表示第一行1, 第二行3……
            """
            if row == n:
                ans.append(trans(visited))
                return
            for col in range(n):
                if not conflict(row, col, visited):
                    dfs(row + 1, visited + [col])
        dfs(0, [])
        return ans
