# 2023-09-03

class Solution:
    def waysToChange(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in (1, 5, 10, 25):
            for j in range(1, n + 1):
                if i <= j:
                    # dp[j] = dp[j] % 1000000007 + dp[j-i] % 1000000007
                    dp[j] = dp[j] + dp[j-i] # Python不会溢出，不需要取模
        return dp[n] % 1000000007
