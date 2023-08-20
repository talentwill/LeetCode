class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) {
            return;
        }

        bool row0 = false;
        bool col0 = false;
        int m = matrix.size();
        int n = matrix[0].size();

        // 第 0 行是否含有0
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }

        // 第 0 列是否含有0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }

        // 剩余行列中的元素，是否含0，含0则把对应的0列0行标记
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // 对应列标记
                    matrix[i][0] = 0; // 对应行标记
                }
            }
        }
        // 再次遍历，根据标记去设置 0 
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 若0行有0，将第0行全设置0
        if (row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        // 若0列有0，将第0列全设置0
        if (col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};