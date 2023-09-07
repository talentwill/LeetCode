class Solution:
    def pileBox(self, box: List[List[int]]) -> int:
        box = tuple(sorted(box))  # 排序，使得小箱子在前面
        dp = [h for _, _, h in box]  # 只有自己一个箱子的高度
        for i in range(len(box)):
            for j in range(i):
                # 如果前面的箱子比自己的小，说明可以堆
                if all(s > t for s, t in zip(box[i], box[j])):
                    # 比较堆起来的高度，自身+前面箱子的最优解
                    dp[i] = max(dp[i], dp[j] + box[i][2])
        return max(dp)
