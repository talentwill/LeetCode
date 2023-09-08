// 2023-09-08
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t)
    {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (i >= 0 and i < m and j >= 0 and j < n) {
            if (matrix[i][j] == t) {
                return true;
            }
            // Z 字型搜索方法
            if (matrix[i][j] > t) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
// 2023-09-08
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t)
    {
        if (m.empty() or m[0].empty()) {
            return false;
        }
        for (const auto& row : m) {
            if (t >= row.front() and t <= row.back()) {
                if (binary_search(begin(row), end(row), t)) {
                    return true;
                }
            }
        }
        return false;
    }
};