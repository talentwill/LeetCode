# 2023-09-03
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m = len(image)
        if m == 0:
            return image
        n = len(image[0])
        vis = [[False] * n for _ in range(m)]
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        oldColor = image[sr][sc]

        def dfs(sr, sc):
            # 越界判断
            if sr < 0 or sr >= m or sc < 0 or sc >= n:
                return
            # 颜色不相同
            if image[sr][sc] != oldColor:
                return
            # 已经访问过
            if vis[sr][sc]:
                return
            vis[sr][sc] = True
            image[sr][sc] = newColor
            for r, c in dirs:
                dfs(sr + r, sc + c)
        dfs(sr, sc)
        return image
