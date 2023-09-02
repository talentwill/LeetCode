class Solution {
public:
    int multiply(int A, int B)
    {
        return dfs(min(A, B), max(A, B), 0);
    }

    int dfs(int cnt, int base, int ans)
    {
        return cnt > 0 ? dfs(cnt - 1, base, base + ans) : ans;
    }
};