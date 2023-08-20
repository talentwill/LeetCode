class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        // 上下翻转
        std::reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 对角线翻转
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};