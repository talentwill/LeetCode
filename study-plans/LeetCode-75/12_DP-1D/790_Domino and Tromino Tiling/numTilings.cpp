// 2023-03-16
class Solution {
public:
    int numTilings(int n) {
        vector<int> dp(max(4, n + 1));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        int mod = 1e9 + 7;
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] % mod + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};